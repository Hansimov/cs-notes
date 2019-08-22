/*
- Concise and fast DP solution using 2D array instead of HashMap with text and video explanation. - LeetCode Discuss 
    https://leetcode.com/problems/frog-jump/discuss/193816/Concise-and-fast-DP-solution-using-2D-array-instead-of-HashMap-with-text-and-video-explanation.
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
#include <math.h>
#include <limits.h>

using namespace std;

bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<vector<bool>> dp(n,vector<bool>(n+1,false));
    // dp[i][j]: whether stones i can jump distance j

    dp[0][1]=true;

    for (int i=1; i<n; ++i) {
        for (int j=0; j<i; ++j) {
            int dist = stones[i] - stones[j];
            if (dist>i || !dp[j][dist])
                continue;
            if (i==n-1)
                return true;
            dp[i][dist] = true;
            dp[i][dist-1] = true;
            dp[i][dist+1] = true;
        }
    }
    return false;
}

string filename = "0403.txt";
const auto& myFunc = canCross;

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
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
    for (int i=0; i<vr.size(); ++i) {
        bool res = myFunc(vn[i]);
        bool is_correct = (int)res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}