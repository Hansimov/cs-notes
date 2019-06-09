// LeetCode132——分割回文串II
//  https://blog.csdn.net/qq_41231926/article/details/85335825
// [C++] LeetCode 132. 分割回文串 II
//  https://blog.csdn.net/lv1224/article/details/79973374
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
    if (s.size()==0) return 0;
    int cut[s.size()+1]; // cut[i]: min cut of s[0:i+1)
    bool pal[s.size()+1][s.size()+1]; // pal[i][j]: Is s[i:j+1) palindrome

/* (i,j) iteration order:
line 0: (0,0)->(1,1)->(2,2)->        ... ->(n-1,n-1)
line 1:        (0,1)->(1,2)->(2,3)-> ... ->(n-2,n-1)
line 2:               (0,2)->(1,3)-> ... ->(n-3,n-1)
                      ...
line n-3:                (0,n-3)->(1,n-2)->(2,n-1)
line n-2:                         (0,n-2)->(1,n-1)
line n-1:                                ->(0,n-1)
*/
    int low, high;
    for (int i=0; i<s.size(); ++i) {
        for (int j=0; j<s.size()-i; ++j) {
            low = j;
            high = low + i;
            if (s[low]==s[high]) {
                if (high-low<=2){
                    pal[low][high] = true;
                } else {
                    pal[low][high] = pal[low+1][high-1];
                }
            } else {
                pal[low][high] = false;
            }
        }
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