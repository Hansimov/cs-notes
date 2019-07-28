/*
- Why factor 2 or 3? The math behind this problem. - LeetCode Discuss 
    https://leetcode.com/problems/integer-break/discuss/80721/Why-factor-2-or-3-The-math-behind-this-problem.
- O(log(n)) Time solution with explanation - LeetCode Discuss 
    https://leetcode.com/problems/integer-break/discuss/80785/O(log(n))-Time-solution-with-explanation
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

int integerBreak(int n) {
    if (n<=2) return 1;
    if (n==3) return 2;

    int r;
    if      (n%3==0)
        r = pow(3,n/3);
    else if (n%3==1)
        r = 4*pow(3,(n-4)/3);
    else
        r = 2*pow(3,(n-2)/3);
    return r;
}

string filename = "0343.txt";
const auto& myFunc = integerBreak;

int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open(filename);

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
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}