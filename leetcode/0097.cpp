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
bool isInterleave(string s1, string s2, string s3) {
    if (s1.size()+s2.size() != s3.size())
        return false;
    int p=0, q=0;
    vector<vector<int>> v;
    vector<int> vtmp;
    int i=0;
    while (i<s3.size()) {
        if (s3[i] == s1[p] && s3[i]==s2[q]) {
            v.push_back({p,q});
        }
        if (s3[i] == s1[p]) {
            ++p;
        }
        else if (s3[i] == s2[q]) {
            ++q;
        }
        else {
            if (v.empty()) {
                return false;
            } else {
                vtmp = v.back();
                v.pop_back();
                p = vtmp[0];
                q = vtmp[1]+1;
                i = p+q-1; // Caution the -1 here: later we will ++i
            }
        }
        ++i;
    }

    return true;
}
// };

int main() {
    string sin, rin, s1, s2, s3;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2, vs3;

    ifstream fp;
    fp.open("0097.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> s1 >> s2 >> s3;
        vs1.push_back(s1);
        vs2.push_back(s2);
        vs3.push_back(s3);
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
        int res = isInterleave(vs1[i], vs2[i], vs3[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += 2;
    }

    return 0;
}