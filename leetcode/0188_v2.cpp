// Refer to leetcode 0123
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
int maxProfit(int K, vector<int>& prices) {
    if (prices.empty()) return 0;
    K = min(K, int(prices.size()/2)+1); // K may be large

    return 0;
}
// };

int main() {
    string sin, rin;
    vector<string> vs;
    vector<int> vk;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0188.txt");

    int d;
    int k;
    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        stringstream ss(sin);

        ss >> k;
        vk.push_back(k);
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
        int res = maxProfit(vk[i], vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}