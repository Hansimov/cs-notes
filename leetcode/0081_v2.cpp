/*
= My 8ms C++ solution (o(logn) on average, o(n) worst case) - LeetCode Discuss 
    https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C%2B%2B-solution-(o(logn)-on-average-o(n)-worst-case)
    https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C++-solution-(o(logn)-on-average-o(n)-worst-case)/112460
= leetcode 81 - TempterCyn的博客 - CSDN博客 
    https://blog.csdn.net/TempterCyn/article/details/84728538
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

bool searchInRotatedSortedArray(vector<int>& v, int t) {
    int n = v.size();
    if (v.size() == 0) return false;

    int l=0, r=n-1, m;

    while (l<=r) {
        m = l+(r-l)/2;
        if (v[m]==t) return true;

        if (v[l]==v[m] && v[m]==v[r]) {
            l++; r--;
        } else if (v[l]<=v[m]) {
            if (v[l]<=t && v[m]>t)
                r = m-1;
            else
                l = m+1;
        } else { // v[l]>v[m]
            if (v[m]<t && v[r]>=t)
                l = m+1;
            else 
                r = m-1;
        }
    }
    return false;
}


string filename = "0081.txt";
const auto& myFunc = searchInRotatedSortedArray;

int main() {
    string vin, nrin;
    vector<vector<int>> vv;
    vector<int> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, vin, '\n')) {
        stringstream sv(vin);

        vector<int> vvi = {};
        while (sv >> d) {
            vvi.push_back(d);
        }
        vv.push_back(vvi);

        getline(fp, nrin, '\n');
        stringstream snr(nrin);
        snr >> d;
        vn.push_back(d);
        snr >> d;
        vr.push_back(d);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vv[i],vn[i]);
        bool is_correct = (res==1)==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}