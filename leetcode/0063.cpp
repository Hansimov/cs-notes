#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// class Solution {
// public:
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) return 0;
    if (obstacleGrid[0].empty()) return 0;

    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    double dp[row+1][col+1]; // dp[i][j]: number of possibilities of i*j grid
    memset(dp, 0, sizeof(dp[0][0])*(row+1)*(col+1));

    for (int i=0; i<row; ++i) {
        if (obstacleGrid[i][0]==0) {
            dp[i+1][1] = 1;
        }
        else {
            dp[i+1][1] = 0;
            break;
        }
    }
    for (int j=0; j<col; ++j) {
        if (obstacleGrid[0][j]==0) {
            dp[1][j+1] = 1;
        }
        else {
            dp[1][j+1] = 0;
            break;
        }
    }
    for (int i=1; i<row; ++i) {
        for (int j=1; j<col; ++j) {
            if (obstacleGrid[i][j] == 0) {
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
            } else {
                dp[i+1][j+1] = 0;
            }
        }
    }

    return (int)dp[row][col];
}
// };

int main() {
    string sin;
    int rr, row, col, state;
    vector<vector<vector<int>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open("0063.txt");

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
                vg.back()[i].push_back(state);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = uniquePathsWithObstacles(vg[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        // printf("%d %d\n", vg[i].size(), vg[i][0].size());
        line += vg[i].size()+1;
    }

    return 0;
}