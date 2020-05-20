#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    vector<string> vs;
    ifstream ifs("8-4 input.txt");
    while (getline(ifs, line)) {
        vs.push_back(line);
    }

    for (auto &s: vs) {
        istringstream iss(s);
        string word;
        while (iss>>word)
            cout << word << endl;
    }

    return 0;
}