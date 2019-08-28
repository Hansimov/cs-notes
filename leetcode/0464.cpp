/*
= Java solution using HashMap with detailed explanation - LeetCode Discuss 
    https://leetcode.com/problems/can-i-win/discuss/95277/Java-solution-using-HashMap-with-detailed-explanation
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
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <limits.h>

using namespace std;

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int m = maxChoosableInteger;
    int d = desiredTotal;

    if ((m+1)*m/2<d) return false;
    if (m>=d) return true;

    return false;
}

string filename = "0464.txt";
const auto& myFunc = canIWin;

int main() {
    string sin;
    int r, n, t;
    vector<int> vr, vn, vt;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> r >> n >> t;
        vr.push_back(r);
        vn.push_back(n);
        vt.push_back(t);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        bool res = myFunc(vn[i],vt[i]);
        bool is_correct = (int)res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}