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
int climbStairs(int n) {
    if (n==0) return 0;
    else if (n==1) return 1;
    else if (n==2) return 2;

    int dp[n+1];
    for (int i=0; i<n+1; ++i) {
        dp[i] = 0;
    }

    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<n+1; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
};


int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open("0070.txt");

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
        int res = climbStairs(vn[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 1;
    }

    return 0;
}