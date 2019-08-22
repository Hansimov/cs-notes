#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

bool isSubsequence(string s, string t) {
    if (s.size()==0) return true;
    int ids=0,idt=0;
    while (idt < t.size()) {
        if (s[ids]==t[idt]) {
            ids++;
            if (ids==s.size())
                return true;
        }
        idt++;
    }
    return false;
}

string filename = "0392.txt";
const auto& myFunc = isSubsequence;

int main() {
    string sin,s1,s2;
    int r;
    vector<int> vr;
    vector<string> vs1, vs2;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> r >> s1 >> s2;
        vr.push_back(r);
        vs1.push_back(s1);
        vs2.push_back(s2);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vs1[i], vs2[i]);
        bool is_correct = ((int)res==vr[i]);
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}