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
    else if (argc < 1) {
        cerr << "Not enough arguments. Usage: " << argv[0] << " [LOOP_BOUND] [PRINT_INTERVAL]" << endl;
        return 1;
    }

    float LOOP_BOUND = argv[1] ? stof(argv[1]) : 1000000000; // Default to 1 billion if no argument is provided
    unsigned long PRINT_INTERVAL = argv[2] ? stoul(argv[2]) : 100000000; // Default to printing every 100 million iterations

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