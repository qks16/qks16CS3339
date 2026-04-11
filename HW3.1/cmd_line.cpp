#include<iostream>
#include<cstdlib>   // for atoi
#include <string>

#include "cache_class.cpp"

using namespace std;

  
int main(int argc, char*argv[]) {

  /* check if the correct number of arguments have been passed; bail otherwise */
  if (argc < 4) {
    cout << "Usage: " << endl;
    cout << "   ./cache num_entries associativity filename" << endl;
    return 0;
  }

  /* get args; all args come in as strings; need to convert to int with atoi() */
  unsigned entries = atoi(argv[1]);
  unsigned assoc = atoi(argv[2]);

  string input_filename = argv[3];

  /* print the args */
  cout << "Number of entries: " << entries << endl;
  cout << "Associativity: " << assoc << endl;
  cout << "Input File Name: " << input_filename << endl;

  //determine output file name based on input file name
  string output_filename = input_filename.substr(0, input_filename.find_last_of('_')) + "_output";
  cout << "Output File Name: " << output_filename << endl;

  cout << "Simulating cache behavior..." << endl;

  ifstream inputFile(input_filename);
  if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

  Cache cache(entries, assoc);

  ofstream outputFile(output_filename);

    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file." << endl;
        return 1;
    }

  string address;
    while (inputFile >> address) {
        unsigned long addr = stoul(address, nullptr, 16); // convert hex string to unsigned long
        bool hit = cache.hit(outputFile, addr);
        if (!hit) {
          cache.update(outputFile, addr);
        }
    }
    inputFile.close();
    outputFile.close();
  
  return 0;
}