#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned long ul1 = 3, ul2 = 7;
    // 32 bits
    // ul1: 0101
    // ul2: 0111
    cout << (ul1 & ul2) << endl;  // 3
    cout << (ul1 | ul2) << endl;  // 7
    cout << (ul1 && ul2) << endl; // 1(true)
    cout << (ul1 || ul2) << endl; // 1(true)

    return 0;
}