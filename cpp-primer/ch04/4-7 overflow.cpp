#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    short s = 32767;
    cout << ++s << endl; // -32768

    unsigned int ui = 0;
    cout << --ui << endl; // 4294967295

    unsigned short us = 65535;
    cout << ++us << endl; // 0



    return 0;
}