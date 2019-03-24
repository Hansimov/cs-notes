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
int numTrees(int n) {
    if (n==0) return 0;
    int dp[n+1]; // dp[i]: num of trees when n==i
    for (int i=0; i<n+1; ++i) {
        dp[i] = 0;
    }
    dp[0] = 1; // Caution!

    int tmp;
    for (int i=1; i<n+1; ++i) {
        tmp = 0;
        for (int p=0; p<i; ++p) {
            tmp += dp[p] * dp[i-1-p];
        }
        dp[i] = tmp;
    }

    return dp[n];
}
// };


int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open("0096.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> n >> r;
        vn.push_back(n);
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = numTrees(vn[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 1;
    }

    return 0;
}