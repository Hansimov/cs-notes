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

class Solution {
public:
int maxProfit(vector<int>& prices) {
    if (prices.empty())
        return 0;

    int minnum = prices[0];
    int maxnum = prices[0];
    int maxpr = 0;

    for (int i=1; i<prices.size(); ++i) {
        if (prices[i]>maxnum) {
            maxnum = prices[i];
        }
        else {
            maxpr = max(maxpr, maxnum-minnum);
            if (prices[i] < minnum) {
                minnum = prices[i];
                maxnum = prices[i];
            }
        }
    }

    maxpr = max(maxpr, maxnum-minnum);
    return maxpr;
}
};

int main() {
    string sin, rin;
    vector<string> vs;
    vector<vector<int>> vn;
    vector<int> vr;

    ifstream fp;
    fp.open("0121.txt");

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
    for (int i=0; i<vs.size(); ++i) {
        int r = maxProfit(vn[i]);
        printf("%d\t%d\t%d\t%d\n", r==vr[i], 2*i+1, vr[i], r);
        // for (int j=0; j<vn[i].size(); ++j) {
        //     printf("\n%d", vn[i][j]);
        // }
    }

    return 0;
}