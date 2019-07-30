/*
- Sorting 2D Vector in C++ | Set 1 (By row and column) - GeeksforGeeks 
    https://www.geeksforgeeks.org/sorting-2d-vector-in-c-set-1-by-row-and-column/
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

// sort 2d vector: width ascend, height discend
static bool sort2d(vector<int> v1, vector<int> v2) {
    if (v1[0] == v2[0])
        return v1[1] > v2[1];
    else
        return v1[0] < v2[0];
}

int lengthOfLIS(vector<int>& nums) {
    if (nums.size()==0) return 0;

    int n = nums.size();

    // dp[i]: len of LIS ends with i-th element
    int dp[n] = {};
    dp[0] = 1;

    for (int i=1; i<n; ++i) {
        dp[i] = 1;
        for (int j=0; j<i; ++j) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i],dp[j]+1);
        }
    }

    // cout << distance(dp,max_element(dp, dp+n));
    return *max_element(dp, dp+n);
}

int maxEnvelopes(vector<vector<int>>& envs) {
    // for (auto env:envs) {
    //     cout << env[0] << "-" << env[1] << " ";
    // }
    // cout << endl;

    sort(envs.begin(), envs.end(), sort2d);

    // for (auto env:envs) {
    //     cout << env[0] << "-" << env[1] << " ";
    // }
    // cout << endl;

    vector<int> heights = {};
    for (auto env:envs) {
        heights.push_back(env[1]);
    }

    return lengthOfLIS(heights);
}

string filename = "0354.txt";
const auto& myFunc = maxEnvelopes;

int main() {
    string vin, rin;
    vector<vector<vector<int>>> vv;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, vin, '\n')) {
        stringstream sv(vin);

        vector<int> vvt = {};
        while (sv>>d) {
            vvt.push_back(d);
        }

        vector<vector<int>> vvi = {};
        for (int i=0; i<vvt.size()/2; ++i) {
            vvi.push_back({vvt[2*i],vvt[2*i+1]});
        }
        vv.push_back(vvi);

        getline(fp, rin, '\n');
        vr.push_back(stoi(rin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vv[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}