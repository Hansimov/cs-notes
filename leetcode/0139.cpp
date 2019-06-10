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
bool wordBreak(string s, vector<string>& wordDict) {

    
    return false;
}
// };


int main() {
    string sin, rin, s, word;
    int r;
    vector<string> vs;
    vector<vector<string>> vw;
    vector<int> vr;

    ifstream fp;
    fp.open("0139.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s;
        vs.push_back(s);
        getline(fp, rin, '\n');
        stringstream sr(rin);
        sr >> r;
        vr.push_back(r==1);
        vector<string> vwi = {};
        while (sr >> word) {
            vwi.push_back(word);
        }
        vw.push_back(vwi);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        bool res = wordBreak(vs[i], vw[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}