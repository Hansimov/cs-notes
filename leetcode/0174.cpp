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

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    if (m==0) return 1;
    int n = dungeon[0].size();
    vector<vector<int>> hp(m+1,vector<int>(n+1,INT_MAX));
    hp[m][n-1] = 1;
    hp[m-1][n] = 1;
    for (int i=m-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            hp[i][j] = max(1,min(hp[i+1][j],hp[i][j+1])-dungeon[i][j]);
        }
    }

    return hp[0][0];
}

string filename = "0174.txt";
const auto& myFunc = calculateMinimumHP;

int main() {
    string sin;
    int row, col, rr, ele;
    vector<vector<vector<int>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> rr;
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
        int res = myFunc(vg[i]);
        bool is_correct = res==vr[i];
        printf("%s\t%d\t%d\t%d\n", is_correct?" ":"x", line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += vg[i].size()+1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}