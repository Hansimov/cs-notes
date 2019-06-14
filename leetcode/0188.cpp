// Refer to leetcode 0123
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
int maxProfit(int K, vector<int>& prices) {
    if (prices.empty()) return 0;
    K = min(K, int(prices.size()/2)+1); // K may be large
    // dp[k,i]: max profit of prices[0:i] at most k trades
    // dp[k,i] = max(dp[k,i-1], max(dp[k-1,j] + prices[i]-prices[j]))
    //         = max(dp[k,i-1], prices[i] + max(dp[k-1,j]-prices[j]))
    //          where j in [0,i-1]
    int diff = 0;

    vector<vector<int>> dp(K+1, vector<int>(prices.size(), 0));

    for (int k=1; k<=K; ++k) {
        diff = dp[k-1][0] - prices[0];
        for (int i=1; i<prices.size(); ++i) {
            dp[k][i] = max(dp[k][i-1], prices[i]+diff);
            diff = max(diff, dp[k-1][i]-prices[i]);
        }
    }


    return dp[K][prices.size()-1];
}
// };

int main() {
    string sin, rin;
    vector<string> vs;
    vector<int> vk;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0188.txt");

    int d;
    int k;
    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        stringstream ss(sin);

        ss >> k;
        vk.push_back(k);
        vector<int> vni = {};
        while (ss >> d) {
            vni.push_back(d);
        }
        vn.push_back(vni);

        getline(fp, rin, '\n');
        vr.push_back(stoi(rin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vs.size(); ++i) {
        // if (i+1!=2) continue;
        int res = maxProfit(vk[i], vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}