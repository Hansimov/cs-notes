#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void func(string &s, const string prefix, const string suffix) {
    s.insert(s.begin(), prefix.begin(), prefix.end());
    s.append(suffix);
}

int main() {
    string s = "Alice";
    func(s, "Mr.", "Jr.");
    cout << s << endl;

    return 0;
}