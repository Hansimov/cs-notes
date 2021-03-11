#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int numOfString(string s1, string s2, int len1, int len2) {
    int mod = 1000007;
    int res = 0;
    vector<int> dp(len2+1,0);
    for (int i=1; i<=len2; ++i) {
        dp[i] =  (26*dp[i-1]) % mod;
        if (i<=s1.size())
            dp[i] -= (s1[i-1]-'a'+1);
        if (i<=s2.size())
            dp[i] += (s2[i-1]-'a'+1);
        if (i==s2.size())
            dp[i]--;
        if (i>=len1)
            res += dp[i];
    }
    return res;
}

int main() {
    string s1, s2;
    int len1, len2;
    while (cin >> s1 >> s2 >> len1 >> len2) {
        cout << numOfString(s1,s2,len1,len2) << endl;
    }
    return 0;
}