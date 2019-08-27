/*
- 8-line O(N^2) solution without long type conversion (with key points and comments) - LeetCode Discuss 
    https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/92838/8-line-O(N2)-solution-without-long-type-conversion-(with-key-points-and-comments)
- Detailed explanation for Java O(n^2) solution - LeetCode Discuss 
    https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/92822/Detailed-explanation-for-Java-O(n2)-solution
- [LeetCode] Arithmetic Slices II - Subsequence 算数切片之二 - 子序列 - Grandyang - 博客园 
    https://www.cnblogs.com/grandyang/p/6057934.html
- O(N^2) MLE/TLE in C++? Try this one, Concise and Fast. - LeetCode Discuss 
    https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/92850/O(N2)-MLETLE-in-C%2B%2B-Try-this-one-Concise-and-Fast.
- 11 line Python O(n^2) solution - LeetCode Discuss 
    https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/92852/11-line-Python-O(n2)-solution
- map和unordered_map的差别和使用 - 陈云佳的专栏 - CSDN博客 
    https://blog.csdn.net/BillCYJ/article/details/78985895
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
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <limits.h>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    if (A.empty()) return 0;
    int n = A.size();
    vector<unordered_map<long long, int >> dp(n);
    unordered_set<int> s(A.begin(), A.end());
    int res = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i-1; j >= 0; --j) {
            long long d = (long long)A[i] - (long long)A[j];
            int tmp = dp[j].count(d) ? dp[j][d] : 0;
            if (tmp) res += tmp;
            if (s.count(A[i]+d)) dp[i][d] += 1 + tmp;
        }
    }
    return res;
}

string filename = "0446.txt";
const auto& myFunc = numberOfArithmeticSlices;

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
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}