/*
= Concise O(log N) Binary search solution - LeetCode Discuss 
    https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14425/Concise-O(log-N)-Binary-search-solution
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

int searchInRotatedSortedArray(vector<int>& nums, int target) {
    int n = nums.size();
    if (n==0) return -1;

    int lo=0,hi=n-1;
    while (lo<hi) {
        int mid = (lo+hi)/2;
        if (nums[mid] > nums[hi])
            lo = mid+1;
        else
            hi = mid;
    }
    int off=lo;
    lo=0,hi=n-1;
    while (lo<=hi) {
        int mid = (lo+hi)/2;
        int realmid = (mid+off)%n;
        if (nums[realmid]==target)
            return realmid;
        else if (nums[realmid]<target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

string filename = "0033.txt";
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
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}