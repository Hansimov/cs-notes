#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream ifs("./8-9 input.txt");
    vector<string> vs;
    string s;
    // while (ifs >> s) {
    while (getline(ifs, s)) {
        vs.push_back(s);
    }

    // for (auto s: vs) {
    for (const auto &s: vs) {
        cout << s << endl;
    }

    return 0;
}