#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool leSize(string const& s, string::size_type sz) {
    return s.size() <= sz;
}

int main() {
    vector<string> v{"abc","abcddd","abcd","ab","abcd","bcd","aabbcc","abcdd","ab","abcd","bcd","aac","bbccd","abdcd","abdbdbdd","abd","abd","ab","abdbddd","ababababa","ab","babababc"};
    cout << count_if(v.begin(), v.end(), bind(leSize, _1, 3)) << endl;

    return 0;
}