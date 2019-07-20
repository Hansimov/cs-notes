#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


// class Solution {
// public:
int maximalSquare(vector<vector<char>>& v) {
    int m = v.size();
    if (m==0) return 0;
    int n = v[0].size();

    int dp[m][n] = {};
    // dp[i][j]: the side length of the square whose right-bottom corner is at (i,j)

    int maxlen = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (i==0 || j==0) {
                dp[i][j] = v[i][j] - '0';
            } else {
                if (v[i][j]=='0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                }
            }
            maxlen = max(maxlen,dp[i][j]);
        }
    }

    return maxlen*maxlen;
}
// };

int main() {
    string sin;
    int row, col, rr, state;
    vector<vector<vector<char>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open("0221.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> rr;
        vr.push_back(rr);
        vg.push_back({});
        for (int i=0; i<row; ++i) {
            getline(fp, sin, '\n');
            stringstream ss(sin);
            vg.back().push_back({});
            for (int j=0; j<col; ++j) {
                ss >> state;
                vg.back()[i].push_back('0'+state);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = maximalSquare(vg[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
       if (res==vr[i]) ++correct_cnt;
        line += vg[i].size()+1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}