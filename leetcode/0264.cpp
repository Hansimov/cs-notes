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

int nthUglyNumber(int n) {
    if (n<=0) return 0;
    int sup[3] = {2,3,5};
    int len = sizeof(sup)/sizeof(*sup);
    int tmp = 0;
    // (2^)p[0],,: pow superscript of 2,3,5
    int p[len] = {};
    // X*2,,: value after tmp multiply 2,3,5
    int v[len] = {};

    // dp[i]: (i+1)-th ugly number
    int dp[n] = {};

    dp[0] = 1;

    for (int i=1; i<n; ++i) {
        for (int j=0; j<len; ++j) {
            v[j] = dp[p[j]] * sup[j];
        }
        tmp = *min_element(v,v+len);
        dp[i] = tmp;
        for (int j=0; j<len; ++j) {
            if (dp[p[j]] * sup[j] == tmp)
                p[j] ++;
        }
    }
    return dp[n-1];
}

int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open("0264.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> n >> r;
        vn.push_back(n);
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = nthUglyNumber(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}