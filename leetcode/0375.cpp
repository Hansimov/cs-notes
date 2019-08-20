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

int dp(int l, int r){
    if (r-l<=0)
        return 0;
    else if (r-l==1)
        return l;
    else if (r-l==2)
        return l+1;
    else {
        int res=INT_MAX;
        int tmp;
        for (int i=l+1;i<=r-1;i++) {
            tmp = i + max(dp(l,i-1),dp(i+1,r));
            res = min(res,tmp);
        }
        return res;
    }
}

// 100 400
// 300 1640

int getMoneyAmount(int n) {
    return dp(1,n);
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