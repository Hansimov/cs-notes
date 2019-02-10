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
int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    if (grid[0].empty()) return 0;

    int row = grid.size();
    int col = grid[0].size();

    int dp[row+1][col+1];
    memset(dp, 0, sizeof(dp[0][0])*(row+1)*(col+1));

    // vector<vector<int> > dp(row+1, vector<int>(col+1, 0));

    for (int i=0; i<row; ++i) {
        dp[i+1][1] = dp[i][1] + grid[i][0];
    }
    for (int j=0; j<col; ++j) {
        dp[1][j+1] = dp[1][j] + grid[0][j];
    }

    for (int i=1; i<row; ++i) {
        for (int j=1; j<col; ++j) {
            dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
        }
    }

    return (int)dp[row][col];
}
// };

int main() {
    string sin;
    int rr, row, col, weight;
    vector<vector<vector<int>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open("0064.txt");

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
                ss >> weight;
                vg.back()[i].push_back(weight);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = minPathSum(vg[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        // printf("%d %d\n", vg[i].size(), vg[i][0].size());
        line += vg[i].size()+1;
    }

    return 0;
}