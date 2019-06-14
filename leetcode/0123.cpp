// A clean DP solution which generalizes to k transactions
//   https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39608/A-clean-DP-solution-which-generalizes-to-k-transactions

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

// class Solution {
// public:
int maxProfit(vector<int>& prices) {
    // dp[k,i]: max profit of prices[0:i] at most k trades
    // dp[k,i] = max(dp[k,i-1], max(dp[k-1,j] + prices[i]-prices[j]))
    //         = max(dp[k,i-1], prices[i] + max(dp[k-1,j]-prices[j]))
    //          where j in [0,i-1]
    if (prices.empty()) return 0;
    int K = 2;
    int res = 0;
    int tmp = 0;
    vector<vector<int>> dp(K+1, vector<int>(prices.size(), 0));

    for (int k=1; k<K+1; ++k) {
        tmp = dp[k-1][0] - prices[0];
        for (int i=1; i<prices.size(); ++i) {
            dp[k][i] = max(dp[k][i-1], prices[i] + tmp);
            tmp = max(tmp, dp[k-1][i]-prices[i]);
        }
    }

    return dp[2][prices.size()-1];
}
// };

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0123.txt");

    int d;
    int c=0;
    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        stringstream ss(sin);

        vector<int> vni = {};
        while (ss >> d) {
            vni.push_back(d);
            // printf("%d ", d);
        }
        vn.push_back(vni);

        getline(fp, rin, '\n');
        vr.push_back(stoi(rin.c_str(),NULL,10));
        // ++c;printf("==%d==\n", c);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    for (int i=0; i<vs.size(); ++i) {
        int r = maxProfit(vn[i]);
        printf("%d\t%d\t%d\t%d\n", r==vr[i], 2*i+1, vr[i], r);
        // for (int j=0; j<vn[i].size(); ++j) {
        //     printf("\n%d", vn[i][j]);
        // }
    }

    return 0;
}