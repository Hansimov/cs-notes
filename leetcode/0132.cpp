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
int minCut(string s) {
    
    return 0;
}
// };

int main() {
    string sin, rin, s1;
    int r;
    vector<int> vr;
    vector<string> vs1;

    ifstream fp;
    fp.open("0132.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1;
        vs1.push_back(s1);
        getline(fp, rin, '\n');
        stringstream sr(rin);
        sr >> r;
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = minCut(vs1[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 2;
    }

    return 0;
}