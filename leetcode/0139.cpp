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
    if (wordDict.empty()) return false;

    int n = s.size();
    bool dp[n+1]; // dp[i]: s[0,i) can be composed from wordDict

    dp[0] = true;

    int maxlen = 0;
    for (string word: wordDict) {
        maxlen = max(maxlen,(int)word.size());
    }

    for (int i=1; i<=n; ++i) {
        dp[i]  = false;
        for (int j=i-1; j>=max(i-maxlen,0); --j) {
            if (dp[j]) {
                if (find(wordDict.begin(),wordDict.end(),s.substr(j,i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[n];
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
        line += 2;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}