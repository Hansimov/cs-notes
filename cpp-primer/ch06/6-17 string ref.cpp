#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool has_cap(const string &s) {
    for (auto &c: s)
        // if ((c-'A') >=0 && (c-'A') <=25)
        if (isupper(c))
            return true;
    return false;
}

string& lower(string &s) {
    for (auto &c: s)
        c = tolower(c);
    return s;
}

int main() {
    cout << has_cap("hello") << endl;
    string s = "hEllo";
    cout << has_cap(s) << endl;

    string s2 = "HEllo";
    cout << lower(s2) << endl;
    cout << s2 << endl;
    return 0;
}