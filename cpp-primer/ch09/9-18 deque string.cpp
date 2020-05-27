#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    string s = "hello world, this is my test string.";
    deque<string> dqs;
    istringstream iss(s);
    string word;
    while (iss >> word) {
        dqs.push_back(word);
    }
    cout << dqs.size() << endl;
    // for (auto &word: dqs) {
    //     cout << word << " ";
    // }

    auto itr = dqs.begin();
    while (itr!= dqs.end()) {
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;

    return 0;
}