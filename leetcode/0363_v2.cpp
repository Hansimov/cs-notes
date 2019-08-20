/*
- LeetCode Queue类(363 621) 题解 - GTMer的专栏 - CSDN博客 
    https://blog.csdn.net/u013145967/article/details/79710044
- [leetcode] 363. Max Sum of Rectangle No Larger Than K 解题报告 - 小榕流光的专栏 - CSDN博客 
    https://blog.csdn.net/qq508618087/article/details/51761270
- Accepted C++ codes with explanation and references - LeetCode Discuss 
    https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references
- 连续子数组最大和 - Treant - 博客园 
    https://www.cnblogs.com/en-heng/p/3970231.html
- Kadane’s Algorithm — (Dynamic Programming) — How and Why does it Work? 
    https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
- Given an array of integers A and an integer k, find a subarray that contains the largest sum, subject to a constraint that the sum is less than k? - Quora 
    https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
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
#include <numeric>
#include <set>

using namespace std;

// class Solution {
// private:
int getMaxSum(vector<int>& nums, int k) {
    int sum = 0, ans = INT_MIN;
    // trick which has been used in maximum of consecutive substring
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        //if (sum == k) return k;
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    if (ans <= k) return ans;
    int cum = 0;
    ans = INT_MIN;
    set<int> sums;
    sums.insert(0);
    for (int i = 0; i < nums.size(); ++i) {
        cum += nums[i];
        auto iter = sums.lower_bound(cum-k);
        if (iter != sums.end()) {
            //if (*iter == target) return k;
            ans = max(ans, cum - *iter);
        }
        sums.insert(cum);
    }
    return ans;
}
// public:
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int row = matrix.size(), col = matrix[0].size();
    int ans = INT_MIN;
    for (int i = 0; i < col; ++i) {
        vector<int> rows(row, 0);
        for (int j = i; j < col; ++j) {
            for (int k = 0; k < row; ++k) {
                rows[k] += matrix[k][j];
            }
            int maxSum = getMaxSum(rows, k);
            if (maxSum == k) return k;
            ans = max(ans, maxSum);
        }
    }
    return ans;
}

// };

string filename = "0363.txt";
const auto& myFunc = maxSumSubmatrix;

int main() {
    string sin;
    int row, col, kk, rr, ele;
    vector<vector<vector<int>>> vg={};
    vector<int> vk;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> kk >> rr;
        vk.push_back(kk);
        vr.push_back(rr);
        vg.push_back({});
        for (int i=0; i<row; ++i) {
            getline(fp, sin, '\n');
            stringstream ss(sin);
            vg.back().push_back({});
            for (int j=0; j<col; ++j) {
                ss >> ele;
                vg.back()[i].push_back(ele);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vg[i],vk[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += vg[i].size()+1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}