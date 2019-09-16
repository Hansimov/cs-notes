/*
= Beats 100% Binary Search with Explanations - LeetCode Discuss 
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/167981/Beats-100-Binary-Search-with-Explanations
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

int findPeakElement(vector<int>& v) {
    int n = v.size();
    if (n<=1) return 0;

    int l=0, r=n-1, m;
    while (l<r) {
        m = l+(r-l)/2;
        if (v[m]>v[m+1])
            r = m;
        else
            l = m+1;
    }
    return l;
}

string filename = "0162.txt";
const auto& myFunc = findPeakElement;

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
        printf("%s\t%d\t%d\t%d\n", is_correct?" ":"x", 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}