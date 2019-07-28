/*
- 白话LeetCode | 321. Create Maximum Number | 追薪吧 
    http://zhuixin8.com/2016/10/02/leetcode-321/
- Create Maximum Number – AlgoBox by dietpepsi 
    https://web.archive.org/web/20160120093629/http://algobox.org/create-maximum-number/
- Share my greedy solution - LeetCode Discuss 
    https://leetcode.com/problems/create-maximum-number/discuss/77285/Share-my-greedy-solution/81245
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

vector<int> maxSub(vector<int> nums, int kk) {
    vector<int> sub = {};
    for (int i=0; i<nums.size(); ++i) {
        while (!sub.empty() && sub.size()+nums.size()-i>kk && sub.back()<nums[i]) {
            sub.pop_back();
        }
    }
    sub.resize(kk);
    // cout << "=" << sub.size() << "=";
    return sub;
}


vector<int> mergeSubs(vector<int> sub1, vector<int> sub2) {
    vector<int> merged = {};
    while (!sub1.empty() || !sub2.empty()) {
        vector<int>& p = sub1 > sub2 ? sub1 : sub2;
        merged.push_back(p[0]);
        p.erase(p.begin());
    }

    return merged;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    if (k==0) return {};

    vector<int> maxVec={};
    int n1=nums1.size(), n2=nums2.size();

    for (int i=max(0,k-n2); i<=min(k,n1); ++i) {
        maxVec = max(maxVec, mergeSubs(maxSub(nums1,i), maxSub(nums2,k-i)));
        // for (int j=0; j<maxVec.size(); ++j) {
        //     cout << maxVec[j] << ">" ;
        // }
        // cout << endl;
    }

    return maxVec;
}


string filename = "0321.txt";
const auto& myFunc = maxNumber;

int main() {
    string sin1, sin2, nin, rin;
    vector<vector<int>> vv1,vv2;
    vector<int> vn;
    vector<vector<int>> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin1, '\n')) {
        getline(fp, sin2, '\n');
        getline(fp, nin, '\n');
        getline(fp, rin, '\n');

        stringstream ss1(sin1);
        stringstream ss2(sin2);
        stringstream sr(rin);

        vector<int> vvi1 = {};
        vector<int> vvi2 = {};
        vector<int> vri = {};

        while (ss1 >> d) vvi1.push_back(d);
        while (ss2 >> d) vvi2.push_back(d);
        while (sr >> d) vri.push_back(d);
        vv1.push_back(vvi1);
        vv2.push_back(vvi2);
        vr.push_back(vri);

        vn.push_back(stoi(nin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        vector<int> res = myFunc(vv1[i],vv2[i],vn[i]);
        bool is_correct = res==vr[i];
        for (int j=0; j<vr[i].size(); ++j) {
            cout << "-" << vr[i][j];
        };
        cout << endl;
        for (int j=0; j<res.size(); ++j) {
            cout << "-" << res[j];
        };
        cout << endl;

        printf("%d\t%d\n", is_correct, 4*i+1);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}