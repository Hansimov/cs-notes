// Online regex tester and debugger
//   https://regex101.com/
// 【每日一题：小Fu讲解】LeetCode 10. Regular Expression Matching
//   https://www.youtube.com/watch?v=KN22ZEpRTFY
// [LeetCode - 动态规划] 10. Regular Expression Matching
//   https://blog.csdn.net/jitianyu123/article/details/71512253

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
bool isMatch(string s, string p) {
    int sz = s.size();
    int pz = p.size();
    bool dp[sz+1][pz+1]; // dp[i][j]: s[0:i) matched by p[0:j)
    memset(dp, false, sizeof(dp[0][0]) * (sz+1) * (pz+1));

    dp[0][0] = true; // s.empty() && p.empty()
    for (int j=0; j<pz; ++j) { // s=="" and p=='?*'
        if (p[j]=='*') {
            dp[0][j+1] = dp[0][j-1];
        }
    }

    for (int i=0; i<sz; ++i) {
        for (int j=0; j<pz; ++j) {
            if (p[j]=='.' || p[j]==s[i]) {
                dp[i+1][j+1] = dp[i][j];
            } else if (p[j]=='*') {
                if (p[j-1]!=s[i] && p[j-1]!='.') {
                    // p[j-1] cannot be '*' since p[j]=='*'
                    dp[i+1][j+1] = dp[i+1][j-1];
                } else {
                    // Hardest part!
                    // s[i]=='a' && p[j-1,j+1)=="a*" or ".*"
                    // p: 1:""; 2:"a"; 3:"aaa..."
                    dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j] || dp[i][j+1];
                }
            } else { // default is false
            }
        }
    }

    return dp[sz][pz];
}
};

int main() {
    string sin, pin;
    ifstream fp;
    fp.open("0010.txt");

    vector<string> vs;
    vector<string> vp;

    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        getline(fp, pin, '\n');
        vp.push_back(pin);
    }

    fp.close();

    for (int i=0; i<vs.size(); ++i) {
        bool is_match = isMatch(vs[i], vp[i]);
        printf("%s\n", is_match?"true":"false");
    }

    return 0;
}