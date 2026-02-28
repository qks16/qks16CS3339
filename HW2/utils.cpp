#include "utils.h"
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void smallProgram(float lb, float pi) {
    float i = 0;
    float j = 0;

    while (i  <= lb) {
        
        if (static_cast<unsigned long>(j) % static_cast<unsigned long>(pi) == 0) {
        cout << i << endl;

        i++;
        j++;

    }

    // cout << "LOOP_BOUND: " << LOOP_BOUND << endl;
    // bitset<32> loop_bound_bits(*reinterpret_cast<unsigned long*>(&LOOP_BOUND));
    // cout << "LOOP_BOUND bits: " << loop_bound_bits << endl;
    // cout << "Sign bit: " << loop_bound_bits[31] << endl;
    // cout << "Exponent bits: ";
    // for (int i = 30; i >= 23; i--) {
    //     cout << loop_bound_bits[i];
    // }
    // cout << endl;
    // cout << "Significand bits: ";
    // for (int i = 22; i >= 0; i--) {
    //     cout << loop_bound_bits[i];
    // }
    // cout << endl;
}