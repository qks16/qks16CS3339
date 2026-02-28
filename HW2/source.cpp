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
    unsigned long PRINT_INTERVAL = stoul(argv[2]);
    float i = 0;
    unsigned j = 0;

    // while (i  <= LOOP_BOUND) {
        
    //     if (j % PRINT_INTERVAL == 0)
    //     cout << i << endl;

    //     i++;
    //     j++;

    // }

    smallProgram(LOOP_BOUND);
    
    return 0;
}