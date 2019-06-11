#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int n = nums.size();
    //tmax when i: max product of subarray ends with nums[i]
    //tmin when i: min product of subarray ends with nums[i] (<=0)
    int tmin = nums[0]; 
    int tmax = nums[0];
    int res = tmax;

    for (int i=1; i<n; ++i) {
        if (nums[i]<0) swap(tmin,tmax);
        tmax = max(nums[i], tmax*nums[i]);
        tmin = min(nums[i], tmin*nums[i]);
        res = max(res, tmax);
    }

    return res;
}
// };

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0152.txt");

    int d;
    int c=0;
    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        stringstream ss(sin);

        vector<int> vni = {};
        while (ss >> d) {
            vni.push_back(d);
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
        // if (i+1!=2) continue;
        int res = maxProduct(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}