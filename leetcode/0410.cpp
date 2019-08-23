/*
- Clear Explanation: 8ms Binary Search Java - LeetCode Discuss 
    https://leetcode.com/problems/split-array-largest-sum/discuss/89817/Clear-Explanation%3A-8ms-Binary-Search-Java
- Java easy binary search solution 8ms - LeetCode Discuss 
    https://leetcode.com/problems/split-array-largest-sum/discuss/89835/Java-easy-binary-search-solution-8ms
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
#include <numeric>
#include <math.h>
#include <limits.h>

using namespace std;

int splitArray(vector<int>& nums, int m) {
    if (nums.size()==0) return 0;

    long max = *max_element(nums.begin(),nums.end());
    if (nums.size()==m) return max;

    long sum = 0;
    for (long num:nums) sum += num;

    long low = max;
    long high = sum;
    long mid = 0;

    while (low<high) {
        mid = (low+high)/2;
        long cum = 0;
        int cnt = 1;
        bool isValid = true;
        for (long num:nums) {
            cum += num;
            if (cum > mid) {
                cum = num;
                cnt++;
                if (cnt > m) {
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return high;
}

string filename = "0410.txt";
const auto& myFunc = splitArray;

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
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}