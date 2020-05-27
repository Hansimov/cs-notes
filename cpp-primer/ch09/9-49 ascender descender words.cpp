#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string no_cender = "aceimnorsuvwxz";
    string sin = "hello world ace in sanimore suva kudart dark souls";
    istringstream iss(sin);

    string longest_no_cender_word = "";
    string word;
    while (iss >> word) {
        if (word.find(no_cender) == string::npos && word.size() > longest_no_cender_word.size())
            longest_no_cender_word = word;
    }
    cout << longest_no_cender_word << endl;

    return 0;
}