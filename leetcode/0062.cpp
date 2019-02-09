#include <iostream>
#include <fstream>
#include <sstream>
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
int uniquePaths(int m, int n) {
    if (m==0 || n==0) return 0;
    int dp[m+1][n+1]; // dp[i][j]: number of possibilities of i*j grid
    memset(dp, 0, sizeof(dp[0][0])*(m+1)*(n+1));

    for (int i=1; i<=m; ++i) {
        dp[i][1] = 1;
    }
    for (int j=1; j<=n; ++j) {
        dp[1][j] = 1;
    }

    for (int i=1; i<m; ++i) {
        for (int j=1; j<n; ++j) {
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
        }
    }

    return dp[m][n];
}
// };

int main() {
    string sin;
    int m, n, rin;
    vector<int> vm, vn, vr;

    ifstream fp;
    fp.open("0062.txt");

    int d;
    int c=0;
    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> m >> n >> rin;
        vm.push_back(m);
        vn.push_back(n);
        vr.push_back(rin);
        // printf("%s %s\n", rin.c_str(), pin.c_str());
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    for (int i=0; i<vm.size(); ++i) {
        int r = uniquePaths(vm[i], vn[i]);
        printf("%d\t%d\t%d\t%d\t\n", r==vr[i], i+1, vr[i], r);
    }

    return 0;
}