/*description: implement a cache simulator. The simulator will take as input (i) the configuration
parameters of a cache and (ii) a sequence of memory addresses requested by the CPU. It will then simulate the
behavior of the configured cache on the given memory references. Upon completion, the simulator will report for
each reference whether it is a hit or a miss in cache.
Each cache entry consists of a valid bit and a tag. The tag should be extracted from the memory address in
the customary way. For the purposes of this homework, no actual data will be stored in the cache. In other
words, hits and misses will be determined by simply analyzing the memory address inputs.*/

#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <cmath>

#include "utils.h"

using namespace std;

//simulator will be invoked with three command-line arguments as follows

//num entries is the total number of entries 
//associativity is the associativity of the cache to be simulated.
//The input memory reference file will contain a list of memory-address-references separated
// by spaces
//You may assume that num entries is a power-of-two and that associativity evenly divides
// num entries. 

int main(int argc, char* argv[]) {
    int numEntries = stoi(argv[1]);
    int associativity = stoi(argv[2]);

    //set up filestream for reading memory reference file
    ifstream inputFile(argv[3]);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    //create cache object with specified parameters
    Cache cache(numEntries, associativity);

    // written to a file called cache sim output. To facilitate testing, each line of the output
    // file should have information about a single memory reference and should be formatted in the following way.
    // [ADDR] : [HIT or MISS]
    // ADDR is a memory address in the input file printed as an integer. [HIT or MISS] indicates the status of
    // the memory reference.

    ofstream outputFile("cache_sim_output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file." << endl;
        return 1;
    }
    //simulate cache behavior for each memory reference
    string address;
    while (inputFile >> address) {
        uint32_t addr = stoul(address, nullptr, 16); // convert hex string to uint32_t
        bool hit = cache.access(addr);
        outputFile << address << " : " << (hit ? "HIT" : "MISS") << endl;
    }
    inputFile.close();
    outputFile.close();




    return 0;
}