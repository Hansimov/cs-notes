class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for (int len=0; len<s.size(); ++len) {
            for (int i=0; i+len<n; ++i) {
                int j = i+len;
                if (len==0)
                    dp[i][j] = true;
                else if (len==1)
                    dp[i][j] = (s[i]==s[j]);
                else
                    dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);

                if (dp[i][j] && (len+1)>res.size())
                    res = s.substr(i, len+1);
            }
        }
        return res;
    }
};