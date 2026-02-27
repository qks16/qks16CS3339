#include "utils.h"
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void smallProgram(float lb) {
    cout << "loop bound: " << lb << endl;

    cout << "Binary representation: " << bitset<32>(*(int*)&lb) << endl;
}