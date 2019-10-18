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

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if (n==0) return 0;

    int l=0, r=0, sum=0, len = INT_MAX;
    while (r<n) {
        sum+=nums[r];
        ++r;
        while (sum>=s) {
            len = min(len, r-l);
            sum -= nums[l];
            l++;
        }
    }

    return len==INT_MAX ? 0 : len;
}

string filename = "0209.txt";
const auto& myFunc = minSubArrayLen;

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
        int res = myFunc(vn[i],vv[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}