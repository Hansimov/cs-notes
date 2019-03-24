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

static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// class Solution {
// public:
int numDecodings(string s) {
    if (s.size()==0) return 0;
    int dp[s.size()+1]; // dp[i]: num of decodings of s[0:i]

    dp[0] = 1;
    if (s[0]!='0')
        dp[1] = 1;
    else
        return 0;

    string s1 = "123456";
    for (int i=1; i<s.size(); ++i) {
        if (s[i] == '0') {
            if (s[i-1]=='1' || s[i-1]=='2')
                dp[i+1] = dp[i-1];
            else
                return 0;
        } else
        if (s1.find(s[i]) != string::npos) {
            if (s[i-1]=='1' || s[i-1]=='2')
                dp[i+1] = dp[i] + dp[i-1];
            else
                dp[i+1] = dp[i];
        } else {
            if (s[i-1]=='1')
                dp[i+1] = dp[i] + dp[i-1];
            else
                dp[i+1] = dp[i];
        }
    }

    return dp[s.size()];
}
// };

int main() {
    string sin, rin, s1;
    int r;
    vector<int> vr;
    vector<string> vs1;

    ifstream fp;
    fp.open("0091.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1;
        vs1.push_back(s1);
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
        int res = numDecodings(vs1[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 2;
    }

    return 0;
}