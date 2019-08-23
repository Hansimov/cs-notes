/*
- 0/1 knapsack detailed explanation - LeetCode Discuss 
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
- Simple C++ 4-line solution using a bitset - LeetCode Discuss 
    https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/Simple-C%2B%2B-4-line-solution-using-a-bitset
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <limits.h>

using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum=0;
    for (int num:nums) sum+=num;
    if (sum%2==1) return false;
    sum/=2;

    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    // dp[i][s]: whether sum s can be gotten from first i elements

    for (int i=0; i<=n; i++) dp[i][0] = true;
    for (int s=1; s<=sum; s++) dp[0][s] = false;

    for (int i=1; i<=n; ++i) {
        for (int s=1; s<=sum; ++s) {
            if (s>=nums[i-1])
                dp[i][s] = dp[i-1][s] || dp[i-1][s-nums[i-1]];
            else
                dp[i][s] = dp[i-1][s];
        }
    }

    return dp[n][sum];
}

string filename = "0416.txt";
const auto& myFunc = canPartition;

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
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
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vs.size(); ++i) {
        bool res = myFunc(vn[i]);
        bool is_correct = (int)res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}