/*
= Clean iterative solution with two binary searches (with explanation) - LeetCode Discuss 
    https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14699/Clean-iterative-solution-with-two-binary-searches-(with-explanation)
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

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> pos(2,-1);
    if (n==0) return pos;

    int lo=0,hi=n-1;

    // search left bound
    while (lo<hi) {
        int mid = (lo+hi)/2;
        if (nums[mid]<target)
            lo = mid+1;
        else
            hi = mid;
    }
    if (nums[lo]!=target)
        return pos;
    else
        pos[0] = lo;

    // search right bound
    hi = n-1; // no need to reset lo
    while (lo<hi) {
        int mid = (lo+hi)/2+1; // biased to right side
        if (nums[mid]>target)
            hi = mid-1;
        else
            lo = mid;
    }
    pos[1] = hi;

    return pos;
}

string filename = "0034.txt";
const auto& myFunc = searchRange;

int main() {
    string sin1, nin, rin;
    vector<vector<int>> vv1;
    vector<int> vn;
    vector<vector<int>> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin1, '\n')) {
        getline(fp, nin, '\n');
        getline(fp, rin, '\n');

        stringstream ss1(sin1);
        stringstream sr(rin);

        vector<int> vvi1 = {};
        vector<int> vri = {};

        while (ss1 >> d) vvi1.push_back(d);
        while (sr >> d) vri.push_back(d);
        vv1.push_back(vvi1);
        vr.push_back(vri);

        vn.push_back(stoi(nin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        vector<int> res = myFunc(vv1[i],vn[i]);
        bool is_correct = res==vr[i];
        for (int j=0; j<vr[i].size(); ++j) {
            cout << "=" << vr[i][j];
        };
        cout << endl;
        for (int j=0; j<res.size(); ++j) {
            cout << "=" << res[j];
        };
        cout << endl;

        printf("%d\t%d\n", is_correct, 4*i+1);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}