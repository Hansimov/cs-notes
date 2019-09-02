/*
= C++ Concise Solution - LeetCode Discuss 
    https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/95448/C%2B%2B-Concise-Solution
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

int findSubstringInWraproundString(string p) {
    if (p.size()==0) return 0;

    vector<int> num(26, 0);
    // num[i]: num of substring endss with char 'a'+i

    num[p[0]-'a'] = 1;
    int len = 1;
    for (int i = 1; i < p.size(); i++) {
        int cur = p[i] - 'a';
        if (p[i]-p[i-1]!=1 && p[i]-p[i-1]!=-25) len = 0;
        num[cur] = max(num[cur], ++len);
    }
    return accumulate(num.begin(), num.end(), 0);
}

string filename = "0467.txt";
const auto& myFunc = findSubstringInWraproundString;

int main() {
    string sin, rin, s1;
    int r;
    vector<int> vr;
    vector<string> vs1;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1;
        vs1.push_back(s1);
        getline(fp, rin, '\n');
        stringstream sr(rin);
        sr >> r;
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vs1[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 2;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}