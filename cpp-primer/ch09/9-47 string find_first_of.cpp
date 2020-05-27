#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s = "ab2c3d7R4E6";
    string numbers = "0123456789";
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string::size_type pos = 0;
    while ((pos=s.find_first_of(numbers,pos)) != string::npos) {
        cout << "number: " << s[pos] << " idx: " << pos << endl;
        ++pos;
    }

    cout << endl;

    pos = 0;
    while ((pos=s.find_first_of(letters,pos)) != string::npos) {
        cout << "letter: " << s[pos] << " idx: " << pos << endl;
        ++pos;
    }


    return 0;
}