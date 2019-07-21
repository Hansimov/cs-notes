/*
- [LeetCode] Longest Increasing Subsequence 最长递增子序列 - Grandyang - 博客园 
    https://www.cnblogs.com/grandyang/p/4938187.html
- algorithm - How to determine the longest increasing subsequence using dynamic programming? - Stack Overflow 
    https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
- Longest Increasing Subsequence Size (N log N) - GeeksforGeeks 
    https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
- Longest increasing subsequence - Wikipedia 
    https://en.wikipedia.org/wiki/Longest_increasing_subsequence
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

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size()==0) return 0;

    int n = nums.size();
    vector <int> v;

    for (auto num : nums) {
        auto idx = lower_bound(v.begin(), v.end(), num);
        if (idx == v.end()) {
            v.push_back(num);
        } else {
            *idx = num;
        }
    }
    return v.size();
}

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0300.txt");

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
        int res = lengthOfLIS(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}