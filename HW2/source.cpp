#include <iostream>
#include <bitset>
#include <string>

#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {

    //check if the number of arguments is greater than 2 or less than 2. if so print appropriate error message and exit with code 1
    if (argc > 3) {
        cerr << "Too many arguments. Usage: " << argv[0] << " [LOOP_BOUND] [PRINT_INTERVAL]" << endl;
        return 1;
    }
    else if (argc < 3) {
        cerr << "Not enough arguments. Usage: " << argv[0] << " [LOOP_BOUND] [PRINT_INTERVAL]" << endl;
        return 1;
    }

    float LOOP_BOUND = stof(argv[1]);
    float PRINT_INTERVAL = stof(argv[2]);

    //smallProgram(LOOP_BOUND, PRINT_INTERVAL);
    
    //output the IEEE-formatted 32-bit representation of both LOOP_BOUND and PRINT_INTERVAL, using the bitset class to display the bits,
    //separating the sign bit, exponent bits, and significand bits with spaces for readability by bit manipulation.

    cout << "LOOP_BOUND: " << bitset<1>(reinterpret_cast<unsigned long&>(LOOP_BOUND) >> 31) 
         <<            " " << bitset<8>((reinterpret_cast<unsigned long&>(LOOP_BOUND) >> 23) & 0xFF) 
         <<            " " << bitset<23>(reinterpret_cast<unsigned long&>(LOOP_BOUND) & 0x7FFFFF)
         << endl;
    
    cout << "PRINT_INTERVAL: " << bitset<1>(reinterpret_cast<unsigned long&>(PRINT_INTERVAL) >> 31)
         <<            " " << bitset<8>((reinterpret_cast<unsigned long&>(PRINT_INTERVAL) >> 23) & 0xFF)
         <<            " " << bitset<23>(reinterpret_cast<unsigned long&>(PRINT_INTERVAL) & 0x7FFFFF)
         << endl;
    

    return 0;
}