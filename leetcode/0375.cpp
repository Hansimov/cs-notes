/*
- Clarification on the problem description. [Problem description need to be updated !!! ] - LeetCode Discuss 
    https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84766/Clarification-on-the-problem-description.-Problem-description-need-to-be-updated-!!!
- Simple DP solution with explanation~~ - LeetCode Discuss 
    https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84764/Simple-DP-solution-with-explanation~~
- Good Solutions to Programming Problems : [LeetCode] Guess Number Higher or Lower II 
    https://artofproblemsolving.com/community/c296841h1273742
- An O(n^2) DP Solution, Quite Hard. - LeetCode Discuss 
    https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84826/An-O(n2)-DP-Solution-Quite-Hard.
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
#include <numeric>
#include <set>

using namespace std;

int dp(vector<vector<int>>& v,int l, int r){
    if (v[l][r] != 0)
        return v[l][r];

    if (r-l<=0)
        v[l][r]=0;
    else if (r-l==1)
        v[l][r]=l;
    else if (r-l==2)
        v[l][r] = l+1;
    else {
        int res=INT_MAX;
        int tmp;
        for (int i=l+1;i<=r-1;i++) {
            tmp = i + max(dp(v,l,i-1),dp(v,i+1,r));
            res = min(res,tmp);
        }
        v[l][r] = res;
    }
    return v[l][r];
}

int getMoneyAmount(int n) {
    vector<vector<int>> v(n+1,vector<int>(n+1,0));
    int res = dp(v,1,n);
    return res;
}


string filename = "0375.txt";
const auto& myFunc = getMoneyAmount;

int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> n >> r;
        vn.push_back(n);
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = myFunc(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}