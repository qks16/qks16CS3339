#ifndef UTILS_H
#define UTILS_H

void printBitRep(float clArg1, float clArg2); //display the IEEE-formatted 32-bit representation of both LOOP_BOUND and PRINT_INTERVAL, using the bitset class to display the bits,
                                              //separating the sign bit, exponent bits, and significand bits with spaces for readability by bit manipulation.

float fMinOverflowThreshold(float clArg1, float clArg2); //find the smallest floating-point value for which an increment by the loop-
                                                         //counter value is lost because there aren’t enough bits in the fraction segment.
#endif // UTILS_H