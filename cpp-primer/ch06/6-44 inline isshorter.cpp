#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline bool is_shorter(string s1, string s2) {
    return s1.size() < s2.size();
}

int main() {
    cout << is_shorter("abc","defg") << endl;

    return 0;
}