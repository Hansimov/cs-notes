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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    return 0.0;
}

string filename = "0004.txt";
const auto& myFunc = findMedianSortedArrays;

int main() {
    string sin1, sin2, rin;
    vector<vector<int>> vv1, vv2;
    vector<double> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin1, '\n')) {
        getline(fp,sin2,'\n');

        stringstream ss1(sin1);
        stringstream ss2(sin2);

        vector<int> vvi1 = {};
        vector<int> vvi2 = {};

        while (ss1 >> d) vvi1.push_back(d);
        while (ss2 >> d) vvi2.push_back(d);

        vv1.push_back(vvi1);
        vv2.push_back(vvi2);

        getline(fp, rin, '\n');
        stringstream sr(rin);
        double d;
        sr >> d;
        vr.push_back(d);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        double res = myFunc(vv1[i],vv2[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%.1f\t%.1f\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}