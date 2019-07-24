/*
- LeetCode312：Burst Balloons - 卷卷萌的博客 - CSDN博客 
    https://blog.csdn.net/mengmengdajuanjuan/article/details/86502077
- leetcode 312. Burst Balloons 分析 - Swartz2015的专栏 - CSDN博客 
    https://blog.csdn.net/swartz2015/article/details/50561199
- LeetCode 312: Brust Balloon 解题与思考 - 码农a嘘的博客 - CSDN博客 
    https://blog.csdn.net/cjl707408282/article/details/77919485
*/

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
#include <limits.h>

using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    if (n==0) return 0;
    nums.insert(nums.begin(),1);
    nums.insert(nums.end(),1);
    n += 2;

    int dp[n][n] = {};
    // dp[i][j]: max coins of (new) nums[i:j+1)

    int lp,rp;
    for (int len=3; len<=n; len++) {
        for (lp=0; lp<=n-len; lp++) {
            rp = lp+len-1;
            for (int i=lp+1; i<=rp-1; ++i) {
                dp[lp][rp] = max(dp[lp][rp], nums[lp]*nums[i]*nums[rp] + dp[lp][i] + dp[i][rp]);
            }
        }
    }

    // for (int i=0; i<n; ++i) {
    //     for (int j=0; j<n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[0][n-1];
}

string filename = "0312.txt";
const auto& myFunc = maxCoins;

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

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
    int correct_cnt=0;
    for (int i=0; i<vs.size(); ++i) {
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}