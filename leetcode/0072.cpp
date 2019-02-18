// Edit Distance | DP-5
//   https://www.geeksforgeeks.org/edit-distance-dp-5/

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

class Solution {
public:
int minDistance(string word1, string word2) {

    if (word1.size()==0) return word2.size();
    if (word2.size()==0) return word1.size();

    int m = word1.size();
    int n = word2.size();
    int dp[m+1][n+1]; // dp[i][j]: minDistance of word1[0:i) and word2[0:j)

    for (int i=0; i<=m; ++i) dp[i][0] = i;
    for (int j=0; j<=n; ++j) dp[0][j] = j;

    for (int i=0; i<word1.size(); ++i) {
        for (int j=0; j<word2.size(); j++) {
            if (word1[i]==word2[j]) {
                dp[i+1][j+1] = dp[i][j];
            } else {
                dp[i+1][j+1] = 1 + min(min(dp[i+1][j], dp[i][j+1]), dp[i][j]);
            }
            // insert:  dp[m][n-1]
            // remove:  dp[m-1][n]
            // replace: dp[m-1][n-1]
        }
    }
    return dp[m][n];
}
};


int main() {
    string sin, rin, s1, s2;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2;

    ifstream fp;
    fp.open("0072.txt");

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
        int res = minDistance(vs1[i], vs2[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 1;
    }

    return 0;
}