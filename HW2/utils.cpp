#include "utils.h"
#include <iostream>
#include <bitset>
#include <string>
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

    // Compute log2 to get fractional exponent difference
    float LoopBoundExponent = log2(clArg1);
    float LoopCounterExponent = log2(clArg2);

    float thresholdExponent = LoopBoundExponent - LoopCounterExponent -2.0f; // -2 to scale to desired output

    // Compute threshold
    int thresholdExpInt = static_cast<int>(floor(thresholdExponent));

    int bias = 127;
    int rawExp = thresholdExpInt + bias;

    if (rawExp <= 0) rawExp = 1;       // avoid denormal
    if (rawExp >= 255) rawExp = 254;   // avoid infinity

    uint32_t thresholdBits = static_cast<uint32_t>(rawExp) << 23; // fraction = 0

    // reinterpret bits as float (via reference cast)
    float threshold = *reinterpret_cast<float*>(&thresholdBits);

    return threshold;

}
