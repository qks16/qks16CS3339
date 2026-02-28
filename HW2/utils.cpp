#include "utils.h"
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void printBitRep(float clArg1, float clArg2) {
    cout << "LOOP_BOUND: " << bitset<1>(reinterpret_cast<unsigned long  &>(clArg1) >> 31) 
         <<            " " << bitset<8>((reinterpret_cast<unsigned long&>(clArg1) >> 23) & 0xFF) 
         <<            " " << bitset<23>(reinterpret_cast<unsigned long&>(clArg1) & 0x7FFFFF)
         << endl;

    cout << "PRINT_INTERVAL: " << bitset<1>(reinterpret_cast<unsigned long  &>(clArg2) >> 31)
         <<                " " << bitset<8>((reinterpret_cast<unsigned long&>(clArg2) >> 23) & 0xFF)
         <<                " " << bitset<23>(reinterpret_cast<unsigned long&>(clArg2) & 0x7FFFFF)
         << endl;

}

float fMinOverflowThreshold(float clArg1, float clArg2) {
    // we need only pay attention to the exponent portion of the floating-point representation, and the
    // threshold value is the difference between the exponents of both the loop-bound and loop-counter. The
    // resulting-number’s fraction segment is all zeroes, and the corresponding base-10 decimal number is that
    // threshold.

    unsigned long loopBoundExponent = (reinterpret_cast<unsigned long&>(clArg1) >> 23) & 0xFF;
    unsigned long printIntervalExponent = (reinterpret_cast<unsigned long&>(clArg2) >> 23) & 0xFF; 

    return static_cast<float>(loopBoundExponent - printIntervalExponent);

}