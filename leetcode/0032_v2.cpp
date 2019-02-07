// LeetCode-32：Longest Valid Parentheses(最长有效括号) -- Hard
//   https://blog.csdn.net/Koala_Tree/article/details/81385559

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
// #include <utility>

using namespace std;

static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// class Solution {
// public:
int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    int maxlen=0;
    int t[s.size()+1];
    int ptr = -1;
    memset(t, -1, sizeof(t));
    t[0] = -2;

    for (int i=0; i<s.size(); ++i) {
        if (s[i]=='(') {
            t[i+1] = ptr;
            ptr = i;
        } else {
            ptr = t[ptr+1];
            if (ptr == -2) {
                ptr = i;
                t[ptr+1] = -2;
            } else {
                if (maxlen<i-ptr)
                    maxlen = i-ptr;
            }
        }
    }
    return maxlen;
}
// };


int main() {
    string sin, din;
    vector<string> vs;
    vector<int> vd;

    ifstream fp;
    fp.open("0032.txt");

    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        getline(fp, din, '\n');
        vd.push_back(stoi(din.c_str(),NULL,10));
    }
    fp.close();

    for (int i=0; i<vs.size(); ++i) {
        int n = longestValidParentheses(vs[i]);
        printf("%d\t%d\t%d\t%d\n", n==vd[i], 2*i+1, vd[i], n);
    }

    return 0;
}