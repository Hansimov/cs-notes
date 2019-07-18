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
int rob(vector<int>& nums) {
    if (nums.size()==0) return 0;
    if (nums.size()==1) return nums[0];

    // nums1 = nums[0:nums.size()-1];
    vector<int> nums1 = vector<int>(nums.begin(), nums.end()-1);
    // nums2 = nums[1:nums.size()];
    vector<int> nums2 = vector<int>(nums.begin()+1, nums.end());

    int dp1[nums.size()];
    int dp2[nums.size()];
    // dp[i]: max money he can rob in numsi[0:i)

    dp1[0] = 0;
    dp1[1] = nums1[0];
    dp2[0] = 0;
    dp2[1] = nums2[0];

    for (int i=1; i<nums.size()-1; ++i) {
        dp1[i+1] = max(dp1[i], nums1[i]+dp1[i-1]);
        dp2[i+1] = max(dp2[i], nums2[i]+dp2[i-1]);
    }

    return max(dp1[nums1.size()], dp2[nums2.size()]);
}
// };

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0213.txt");

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
        int res = rob(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}