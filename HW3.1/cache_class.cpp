#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

class Entry {
public:
  Entry(){
    //testing case with initialized values
    valid = false;
    tag = 0;
    ref = 0;
  }
  //~Entry();

  void display(ofstream& outfile) {
    outfile << "Tag: " << tag << ", Valid: " << valid << ", Ref: " << ref << endl;
  }

  void set_tag(int _tag) { tag = _tag; }
  int get_tag() { return tag; }

  void set_valid(bool _valid) { valid = _valid; }
  bool get_valid() { return valid; }

  void set_ref(int _ref) { ref = _ref; }
  int get_ref() { return ref; }

private:  
  bool valid;
  unsigned tag;
  int ref;
};

class Cache {
public:
  Cache(int numEntries, int associativity) : num_entries(numEntries), assoc(associativity) {
    num_sets = num_entries / assoc;
    entries = new Entry*[num_sets];
    for (int i = 0; i < num_sets; i++) {
      entries[i] = new Entry[assoc];
    }
  }

  ~Cache() {
    for (int i = 0; i < num_sets; i++) {
      delete[] entries[i];
    }
    delete[] entries;
  }

  void display(ofstream& outfile){
    for (int i = 0; i < num_sets; i++) {
      outfile << "Set " << i << ":" << endl;
      for (int way = 0; way < assoc; way++) {
        outfile << "  Way " << way << ": ";
        entries[i][way].display(outfile);
      }
    }
  }


  int get_index(unsigned long addr) {
    return (addr) % num_sets; // Assuming block size of 4 bytes
  }
  int get_tag(unsigned long addr) {
    return addr / (num_sets); // Assuming block size of 4 bytes
  }

  unsigned long retrieve_addr(int way, int index) {
    return (entries[index][way].get_tag() * num_sets + index); // Assuming block size of 4 bytes
  }
  
  bool hit(ofstream& outfile, unsigned long addr){
    int index = get_index(addr);
    int tag = get_tag(addr);
    for (int way = 0; way < assoc; way++) {
      if (entries[index][way].get_valid() && entries[index][way].get_tag() == tag) {
        entries[index][way].set_ref(1); // Set reference bit on hit
        outfile << "HIT: Address " << addr << " found in cache." << endl;
        return true;
      }
    }
    outfile << "MISS: Address " << addr << " not found in cache." << endl;
    return false;
  }

  void update(ofstream& outfile, unsigned long addt){
    int index = get_index(addt);
    int tag = get_tag(addt);
    for (int way = 0; way < assoc; way++) {
      if (!entries[index][way].get_valid()) {
        entries[index][way].set_valid(true);
        entries[index][way].set_tag(tag);
        entries[index][way].set_ref(1); // Set reference bit on update
        outfile << "Updated cache with address " << addt << " at index " << index << ", way " << way << "." << endl;
        return;
      }
    }
    // If all ways are valid, evict the least recently used entry (LRU)
    int lru_way = 0;
    for (int way = 1; way < assoc; way++) {
      if (entries[index][way].get_ref() < entries[index][lru_way].get_ref()) {
        lru_way = way;
      }
    }
    outfile << "Evicting address " << retrieve_addr(lru_way, index) << " from cache." << endl;
    entries[index][lru_way].set_valid(true);
    entries[index][lru_way].set_tag(tag);
    entries[index][lru_way].set_ref(1); // Set reference bit on update
    outfile << "Updated cache with address " << addt << " at index " << index << ", way " << lru_way << "." << endl;
  }
  
private:
  int assoc;
  unsigned num_entries;
  int num_sets;
  Entry** entries;
};