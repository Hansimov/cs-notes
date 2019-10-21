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

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    if (n==0) return {};
    vector<int> v(n,0);
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (nums[j]<nums[i])
                v[i] += 1;
        }
    }
    return v;
}

string filename = "0315.txt";
const auto& myFunc = countSmaller;

int main() {
    string sin1, rin;
    vector<vector<int>> vv1;
    vector<vector<int>> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin1, '\n')) {
        getline(fp, rin, '\n');

        stringstream ss1(sin1);
        stringstream sr(rin);

        vector<int> vvi1 = {};
        vector<int> vri = {};

        while (ss1 >> d) vvi1.push_back(d);
        while (sr >> d) vri.push_back(d);
        vv1.push_back(vvi1);
        vr.push_back(vri);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        vector<int> res = myFunc(vv1[i]);
        bool is_correct = res==vr[i];
        for (int j=0; j<vr[i].size(); ++j) {
            cout << "=" << vr[i][j];
        };
        cout << endl;
        for (int j=0; j<res.size(); ++j) {
            cout << "=" << res[j];
        };
        cout << endl;

        printf("%s\t%d\n", is_correct?" ":"x", 2*i+1);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}