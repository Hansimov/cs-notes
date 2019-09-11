/*
= Don't treat it as a 2D matrix, just treat it as a sorted list - LeetCode Discuss 
    https://leetcode.com/problems/search-a-2d-matrix/discuss/26220/Don't-treat-it-as-a-2D-matrix-just-treat-it-as-a-sorted-list
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

bool searchMatrix(vector<vector<int>>& m, int target) {
    int row = m.size();
    if (row==0) return false;
    int col = m[0].size();
    if (col==0) return false;

    // 2d => 1d: m[x][y] => m[x*col+y]
    // 1d => 2d: m[i] => m[i/col][i%col]
    int lo=0, hi=row*col-1;

    while (lo<=hi) {
        int mid = (lo+hi)/2;
        int x=mid/col, y=mid%col;
        if (m[x][y] == target)
            return true;
        else if (m[x][y] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}

string filename = "0074.txt";
const auto& myFunc = searchMatrix;

int main() {
    string sin;
    int row, col, tt, rr, ele;
    vector<vector<vector<int>>> vg={};
    vector<int> vt;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> tt >> rr;
        vr.push_back(rr);
        vt.push_back(tt);
        vg.push_back({});
        for (int i=0; i<row; ++i) {
            getline(fp, sin, '\n');
            stringstream ss(sin);
            vg.back().push_back({});
            for (int j=0; j<col; ++j) {
                ss >> ele;
                vg.back()[i].push_back(ele);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        bool res = myFunc(vg[i],vt[i]);
        bool is_correct = (res?1:0)==vr[i];
        printf("%s\t%d\t%d\t%d\n", is_correct?" ":"x", line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += vg[i].size()+1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}