/*
- 1ms Java DP Solution with Detailed Explanation - LeetCode Discuss 
    https://leetcode.com/problems/combination-sum-iv/discuss/85036/1ms-Java-DP-Solution-with-Detailed-Explanation
    https://leetcode.com/problems/combination-sum-iv/discuss/85036/1ms-Java-DP-Solution-with-Detailed-Explanation/89664
- C++ template for ALL Combination Problem Set - LeetCode Discuss 
    https://leetcode.com/problems/combination-sum-iv/discuss/85120/C%2B%2B-template-for-ALL-Combination-Problem-Set
- Runtime error ? - LeetCode Discuss 
    https://leetcode.com/problems/combination-sum-iv/discuss/240624/Runtime-error
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
#include <set>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1,0);
    dp[0] = 1;
    for (int i=1; i<target+1; ++i) {
        for (int j=0; j<nums.size(); ++j) {
            if (i-nums[j]>=0)
                dp[i] += dp[i-nums[j]];
        }
    }
    return dp[target];
}


string filename = "0377.txt";
const auto& myFunc = combinationSum4;

int main() {
    string vin, nrin;
    vector<vector<int>> vv;
    vector<int> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, vin, '\n')) {
        stringstream sv(vin);

        vector<int> vvi = {};
        while (sv >> d) {
            vvi.push_back(d);
        }
        vv.push_back(vvi);

        getline(fp, nrin, '\n');
        stringstream snr(nrin);
        snr >> d;
        vn.push_back(d);
        snr >> d;
        vr.push_back(d);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vv[i],vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}