#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void func(string &s, const string prefix, const string suffix) {
    s.insert(s.size(),suffix);
    s.insert(0,prefix);
}

int main() {
    string s = "Bob";
    func(s, "Mr.", "Jr.");
    cout << s << endl;

    return 0;
}