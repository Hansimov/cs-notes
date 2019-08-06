/*
- LeetCode Queue类(363 621) 题解 - GTMer的专栏 - CSDN博客 
    https://blog.csdn.net/u013145967/article/details/79710044
- 连续子数组最大和 - Treant - 博客园 
    https://www.cnblogs.com/en-heng/p/3970231.html
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
#include <numeric>

using namespace std;

int sumSubVec(vector<vector<int>> m, int li,int lj, int ri, int rj) {
    int sum = 0;
    for (int i=li; i<=ri; ++i) {
        for (int j=lj; j<=rj; ++j) {
            sum += m[i][j];
        }
    }
    return sum;
}

int maxSumSubmatrix(vector<vector<int>>& m, int k) {
    if (m.empty()) return 0;
    int row = m.size(), col = m[0].size();

    int roof=INT_MIN;
    int tmp;
    for (int li=0; li<row; ++li) {
        for (int lj=0; lj<col; ++lj) {
            for (int ri=li; ri<row; ++ri) {
                for (int rj=lj; rj<col; ++rj) {
                    tmp = sumSubVec(m,li,lj,ri,rj);
                    if (tmp>roof && tmp<=k) {
                        roof = tmp;
                    }
                }
            }
        }
    }
    return roof;
}


string filename = "0363.txt";
const auto& myFunc = maxSumSubmatrix;

int main() {
    string sin;
    int row, col, kk, rr, ele;
    vector<vector<vector<int>>> vg={};
    vector<int> vk;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> kk >> rr;
        vk.push_back(kk);
        vr.push_back(rr);
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
        int res = myFunc(vg[i],vk[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += vg[i].size()+1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}