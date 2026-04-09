#include <iostream>
#include <bitset>
#include <string>
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
    
    return 0;
}