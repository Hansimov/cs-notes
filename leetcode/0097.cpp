// LeetCode: Interleaving String [097]
//   http://www.voidcn.com/article/p-urihdywq-bv.html

// My DP solution in C++
//   https://leetcode.com/problems/interleaving-string/discuss/31879/My-DP-solution-in-C%2B%2B

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
bool isInterleave(string s1, string s2, string s3) {
    if (s1.size()+s2.size() != s3.size())
        return false;

    bool dp[s1.size()+1][s2.size()+1];
    // dp[i][j]: s1[0:i) and s2[0:j) can represent s3[0:i+j)

    dp[0][0] = true;
    for (int i=0; i<s1.size(); ++i)
        dp[i+1][0] = (s1[i]==s3[i] && dp[i][0]);
    for (int j=0; j<s2.size(); ++j)
        dp[0][j+1] = (s2[j]==s3[j] && dp[0][j]);

    for (int i=0; i<s1.size(); ++i) {
        for (int j=0; j<s2.size(); ++j) {
            dp[i+1][j+1] = (s1[i]==s3[i+j+1] && dp[i][j+1]) 
                        || (s2[j]==s3[i+j+1] && dp[i+1][j]);
        }
    }

    return dp[s1.size()][s2.size()];
}
};

int main() {
    string sin, rin, s1, s2, s3;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2, vs3;

    ifstream fp;
    fp.open("0097.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1 >> s2 >> s3;
        vs1.push_back(s1);
        vs2.push_back(s2);
        vs3.push_back(s3);
        getline(fp, rin, '\n');
        stringstream sr(rin);
        sr >> r;
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = isInterleave(vs1[i], vs2[i], vs3[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 2;
    }

    return 0;
}