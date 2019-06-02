// LeetCode132——分割回文串II
//  https://blog.csdn.net/qq_41231926/article/details/85335825
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

    int cut[s.size()]; // cut[i]: min cut of s[0:i+1)
    bool pal[s.size()][s.size()]; // pal[i][j]: Is s[i:j+1) palindrome

    pal[0][0] = true;
    for (int i=0; i<s.size(); ++i) {
        for (int j=i; j<s.size(); ++j) {
            if (s[i]==s[j]) {
                if (j-i<=2){
                    pal[i][j] = true;
                } else {
                    pal[i][j] = pal[i+1][j-1];
                }
            } else {
                pal[i][j] == false;
            }
        }
    }

    // for (int i=0; i<s.size(); ++i) {
    //     for (int j=0; j<s.size(); ++j) {
    //         cout << pal[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i=0; i<s.size(); ++i) {
        cut[i] = i;
    }
    for (int i=0; i<s.size(); ++i) {
        for (int j=i; j>=0; --j) {
            if (pal[j][i]) {
                if (j==0) {
                    cut[i] = 0;
                } else {
                    cut[i] = min(cut[i], cut[j-1]+1);
                }
            }
        }
    }

    return cut[s.size()-1];
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
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = minCut(vs1[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 2;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}