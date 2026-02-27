#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char* argv[]) {

    cout << "Enter a number: ";
    int num;
    cin >> num;

    cout << "Binary representation: " << bitset<32>(num) << endl;
    
    return 0;
}