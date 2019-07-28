/*
- Four lines, C++, time O(n), space O(n) - LeetCode Discuss 
    https://leetcode.com/problems/counting-bits/discuss/79527/Four-lines-C%2B%2B-time-O(n)-space-O(n)
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

vector<int> countBits(int n) {
    vector<int> dp(n+1, 0);
    for (int i=1; i<=n; ++i) {
        // dp[i] = dp[i&(i-1)] + 1; // i&(i-1) drops the lowest set bit.
        dp[i] = dp[i>>1] + (i&1);
        // dp[i] = dp[i/2] + (i%2==1);
    }
    return dp;
}

string filename = "0338.txt";
const auto& myFunc = countBits;

int main() {
    string nin, rin;
    vector<int> vn;
    vector<vector<int>> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, nin, '\n')) {
        getline(fp, rin, '\n');

        stringstream sr(rin);

        vn.push_back(stoi(nin.c_str(),NULL,10));

        vector<int> vri = {};
        while (sr >> d) vri.push_back(d);
        vr.push_back(vri);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        vector<int> res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        for (int j=0; j<vr[i].size(); ++j) {
            cout << "-" << vr[i][j];
        };
        cout << endl;
        for (int j=0; j<res.size(); ++j) {
            cout << "-" << res[j];
        };
        cout << endl;

        printf("%d\t%d\n", is_correct, 4*i+1);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}