/*
- Share my thinking process - LeetCode Discuss 
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
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

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n==0) return 0;

    int buy = INT_MIN;
    int sell = 0;
    int sell_prev = 0;
    int buy_prev = 0;

    for (int i=0; i<n; ++i) {
        buy_prev = buy;
        buy = max(buy, sell_prev-prices[i]);
        sell_prev = sell;
        sell = max(sell, buy_prev+prices[i]);
    }

    return sell;
}

string filename = "0309.txt";
const auto& myFunc = maxProfit;

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    int d;
    int c=0;
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
        // ++c;printf("==%d==\n", c);
    }
    fp.close();

    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    for (int i=0; i<vs.size(); ++i) {
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\n", is_correct, 2*i+1, vr[i], res);
        if (is_correct) ++correct_cnt;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}