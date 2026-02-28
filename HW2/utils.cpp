#include "utils.h"
#include <iostream>
#include <bitset>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

void printBitRep(float clArg1, float clArg2) {
    cout << "LOOP_BOUND: " << bitset<1>(reinterpret_cast<unsigned long  &>(clArg1) >> 31) 
         <<            " " << bitset<8>((reinterpret_cast<unsigned long&>(clArg1) >> 23) & 0xFF) 
         <<            " " << bitset<23>(reinterpret_cast<unsigned long&>(clArg1) & 0x7FFFFF)
         << endl;

    cout << "LOOP_COUNTER: " << bitset<1>(reinterpret_cast<unsigned long  &>(clArg2) >> 31)
         <<              " " << bitset<8>((reinterpret_cast<unsigned long&>(clArg2) >> 23) & 0xFF)
         <<              " " << bitset<23>(reinterpret_cast<unsigned long&>(clArg2) & 0x7FFFFF)
         << endl;

}

float fMinOverflowThreshold(float clArg1, float clArg2) {

    if (!isfinite(clArg1) || !isfinite(clArg2))
        return 0.0f;

    return std::numeric_limits<float>::max() - clArg2;

}
