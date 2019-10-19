/*
= [LeetCode]Find the Duplicate Number | 书影博客 
    http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/
= Two Solutions (with explanation): O(nlog(n)) and O(n) time , O(1) space, without changing the input array - LeetCode Discuss 
    https://leetcode.com/problems/find-the-duplicate-number/discuss/72844/Two-Solutions-(with-explanation)%3A-O(nlog(n))-and-O(n)-time-O(1)-space-without-changing-the-input-array
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

int findDuplicate(vector<int>& nums) {
    int n = nums.size()-1;
    int l=1, r=n, mid;
    int cnt;

    while (l<=r){
        mid = l+(r-l)/2;
        cnt = 0;
        for (auto num : nums) {
            if (num<=mid)
                ++cnt;
        }
        if (cnt>mid)
            r = mid-1;
        else
            l = mid+1;
    }

    return l;
}

string filename = "0287.txt";
const auto& myFunc = findDuplicate;

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