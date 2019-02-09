#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
// #include <utility>

using namespace std;

static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
bool isMatch(string s, string p) {
    int sz=s.size();
    int pz=p.size();
    bool dp[sz+1][pz+1]; // dp[i][j]: s[0:i) matched by p[0:j)
    memset(dp, false, sizeof(dp[0][0]) * (sz+1) * (pz+1));

    dp[0][0] = true;
    for (int j=0; j<pz; ++j) { // s=="" and p=='?*'
        if (p[j]=='*') {
            dp[0][j+1] = dp[0][j];
        }
    }

    for (int i=0; i<sz; ++i) {
        for (int j=0; j<pz; ++j) {
            if (p[j]=='?' || p[j]==s[i]) {
                dp[i+1][j+1] = dp[i][j];
            } else if (p[j]=='*') {
                dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1] || dp[i][j];
            } else { // default is false
            }
        }
    }

    return dp[sz][pz];
}
};

int main() {
    string sin, rpin, pin, rin;
    vector<string> vs;
    vector<string> vp;
    vector<int> vr;

    ifstream fp;
    fp.open("0044.txt");

    int d;
    int c=0;
    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
        getline(fp, rpin, '\n');
        stringstream ss(rpin);
        ss >> rin >> pin;
        // getline(fp, rin, '\n');
        vr.push_back(rin=="1");
        vp.push_back(pin);
        // printf("%s %s\n", rin.c_str(), pin.c_str());
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    for (int i=0; i<vs.size(); ++i) {
        bool r = isMatch(vs[i], vp[i]);
        printf("%d\t%d\t%d\t%d\t\n", r==vr[i], 2*i+1, vr[i], r);
    }

    return 0;
}