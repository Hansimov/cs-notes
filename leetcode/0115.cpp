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
int numDistinct(string s, string t) {
    if (s.size() < t.size())
        return 0;
    unsigned long dp[s.size()+1][t.size()+1];
    // dp[i][j]: numDistinct of s[0:i) and t[0:j]

    for (int i=0; i<s.size()+1; ++i)
        dp[i][0] = 1;
    for (int j=1; j<t.size()+1; ++j)
        dp[0][j] = 0;
    
    for (int i=0; i<s.size(); ++i) {
        for (int j=0; j<t.size(); ++j) {
            if (s[i] != t[j])
                dp[i+1][j+1] = dp[i][j+1];
            else
                dp[i+1][j+1] = dp[i][j+1] + dp[i][j];
        }
    }
    return dp[s.size()][t.size()];
}
};


int main() {
    string sin, rin, s1, s2;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2;

    ifstream fp;
    fp.open("0115.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1 >> s2;
        vs1.push_back(s1);
        vs2.push_back(s2);
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
        int res = numDistinct(vs1[i], vs2[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 1;
    }

    return 0;
}