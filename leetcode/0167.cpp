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

vector<int> twoSum(vector<int>& v, int t) {
    int n=v.size();
    vector<int> res(1,1);
    if (n==0) return res;

    int l=0, r=n-1;
    while (l<r) {
        if(v[l]+v[r]==t)
            break;
        else if (v[l]+v[r]>t)
            r--;
        else
            l++;
    }
    return vector<int>{l+1,r+1};
}

string filename = "0167.txt";
const auto& myFunc = twoSum;

int main() {
    string sin1, nin, rin;
    vector<vector<int>> vv1;
    vector<int> vn;
    vector<vector<int>> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    while (getline(fp, sin1, '\n')) {
        getline(fp, nin, '\n');
        getline(fp, rin, '\n');

        stringstream ss1(sin1);
        stringstream sr(rin);

        vector<int> vvi1 = {};
        vector<int> vri = {};

        while (ss1 >> d) vvi1.push_back(d);
        while (sr >> d) vri.push_back(d);
        vv1.push_back(vvi1);
        vr.push_back(vri);

        vn.push_back(stoi(nin.c_str(),NULL,10));
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vr.size(); ++i) {
        vector<int> res = myFunc(vv1[i],vn[i]);
        bool is_correct = res==vr[i];
        for (int j=0; j<vr[i].size(); ++j) {
            cout << "=" << vr[i][j];
        };
        cout << endl;
        for (int j=0; j<res.size(); ++j) {
            cout << "=" << res[j];
        };
        cout << endl;

        printf("%s\t%d\n", is_correct?" ":"x", 4*i+1);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}