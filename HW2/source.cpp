#include <iostream>
#include <bitset>
#include <string>
#include <limits>
#include <cmath>

#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {

    //check if the number of arguments is greater than 2 or less than 2. if so print appropriate error message and exit with code 1
    if (argc > 3) {
        cerr << "Too many arguments. Usage: " << argv[0] << " [LOOP_BOUND] [LOOP_COUNTER]" << endl;
        return 1;
    }
    else if (argc < 3) {
        cerr << "Not enough arguments. Usage: " << argv[0] << " [LOOP_BOUND] [LOOP_COUNTER]" << endl;
        return 1;
    }

    float LOOP_BOUND = stof(argv[1]);
    float LOOP_COUNTER = stof(argv[2]);

    //display the IEEE-formatted 32-bit representation of both LOOP_BOUND and PRINT_INTERVAL using printBitRep
    printBitRep(LOOP_BOUND, LOOP_COUNTER);

    //display a message saying if an overflow will occur, find minOverflowThreshold and display it

    float threshold = fMinOverflowThreshold(LOOP_BOUND, LOOP_COUNTER);

    if (LOOP_BOUND < threshold) {
        cout << "\nWarning: possible overflow!" << endl;
        cout << "overflow threshold: " << threshold << endl;

        cout    << bitset<1>(reinterpret_cast<unsigned long  &>(threshold) >> 31)
         << " " << bitset<8>((reinterpret_cast<unsigned long&>(threshold) >> 23) & 0xFF)
         << " " << bitset<23>(reinterpret_cast<unsigned long&>(threshold) & 0x7FFFFF)
         << endl;
    }
    else {
        cout << "\nThere is no overflow!" << endl;
    }

    return 0;
}