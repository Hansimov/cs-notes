/*
= 7-liner C++ beat 98.4%, DFS with early termination check (detailed explanation) - LeetCode Discuss 
    https://leetcode.com/problems/can-i-win/discuss/95320/7-liner-C%2B%2B-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)
    https://leetcode.com/problems/can-i-win/discuss/95320/7-liner-C++-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)/160463
    https://leetcode.com/problems/can-i-win/discuss/95320/7-liner-C++-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)/127969
    https://leetcode.com/problems/can-i-win/discuss/95320/7-liner-C++-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)/238059
= Java solution using HashMap with detailed explanation - LeetCode Discuss 
    https://leetcode.com/problems/can-i-win/discuss/95277/Java-solution-using-HashMap-with-detailed-explanation
*/
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

enum RESULT {UNKNOWN, WIN, LOSE};
// dfs(~) : true: there *exists* a choice which can make current player win
//          false: current player can not win no matter what choice he makes
bool dfs(int max, int t, vector<RESULT> &memo, int k=0) {
    if (t<=0) // the opponent has reached desiredTotal at last step
        return false;
    if (memo[k] != UNKNOWN)
        return memo[k]==WIN;

    // i-th bit of k (base 2): 0: not picked; 1: picked
    for (int i=1; i<=max; ++i) {
        bool isIthNumPicked = (k&1<<i);
        if (isIthNumPicked)
            continue;

        int kUpdatedAfterIthNumPicked = k|(1<<i);
        bool isOpponentHasChanceToWin = dfs(max,t-i,memo,kUpdatedAfterIthNumPicked);
        if (!isOpponentHasChanceToWin) {
            memo[k]=WIN;
            return true;
        }
    }
    // for any choice of current player, the opponent has a chance to win, so the current player can not win
    memo[k] = LOSE;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int max = maxChoosableInteger;
    int t = desiredTotal;

    if (max>t) return true;
    int sum = max*(max+1)/2;
    if (sum<t) return false;
    // if (sum==t) return max%2;

    vector<RESULT> memo(1 << (max+1), UNKNOWN);
    return dfs(max, t, memo);
}


// // class Solution {
//     enum RESULT { UNKNOWN, WIN, LOSE };
// // public:
//     bool dfs(int max, int t, vector<RESULT> &memo, int k = 0) {
//         if (t <= 0) return false;
//         if (memo[k] != UNKNOWN) return memo[k] == WIN;

//         for (int i = 1; i <= max; i++) {
//             if (!(k & 1 << i) && !dfs(max, t - i, memo, k | (1 << i))) {
//                 memo[k] = WIN;
//                 return true;
//             }
//         }
//         memo[k] = LOSE;
//         return false;
//     }
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
//         if (maxChoosableInteger >= desiredTotal) return true;

//         int s = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
//         if (s < desiredTotal) return false;
//         // if (s == desiredTotal) return maxChoosableInteger % 2;
    
//         vector<RESULT> memo(1 << (maxChoosableInteger + 1), UNKNOWN);

//         return dfs(maxChoosableInteger, desiredTotal, memo);
//     }
// private:

// };

string filename = "0464.txt";
const auto& myFunc = canIWin;

int main() {
    string sin;
    int r, n, t;
    vector<int> vr, vn, vt;

    ifstream fp;
    fp.open(filename);

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> r >> n >> t;
        vr.push_back(r);
        vn.push_back(n);
        vt.push_back(t);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        bool res = myFunc(vn[i],vt[i]);
        bool is_correct = (int)res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%s\t%d/%d\n", correct_cnt==vr.size()?"√":"×",correct_cnt, vr.size());

    return 0;
}