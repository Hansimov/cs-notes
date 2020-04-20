#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> s{"hello"," ","world"," ","here"," ","is","\n","new","","earth"};

    for (auto it = s.begin(); it!=s.end() && !it->empty(); ++it) {
        for (auto iq = (*it).begin(); iq!=(*it).end(); ++iq)
            *iq = toupper(*iq);
        cout << *it;
    }

    return 0;
}