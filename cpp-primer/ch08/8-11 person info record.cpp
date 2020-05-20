#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> people;

    ifstream ifs("8-11 input.txt");
    istringstream record;
    while(getline(ifs, line)) {
        PersonInfo info;
        // istringstream record(line);
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (auto &p: people) {
        cout << p.name << ": ";
        for (auto &n: p.phones) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}