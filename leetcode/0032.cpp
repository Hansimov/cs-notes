#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// class Solution {
// public:
int longestValidParentheses(string s) {
    return s.size();
}
// };


int main() {
    string sin;
    vector<string> vs;

    ifstream fp;
    fp.open("0032.txt");

    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
    }
    fp.close();

    for (int i=0; i<vs.size(); ++i) {
        int n = longestValidParentheses(vs[i]);
        printf("%d\n", n);
    }

    return 0;
}