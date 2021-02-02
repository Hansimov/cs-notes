class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=1; i<s.size(); ++i) {
            if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='5'))
                dp[i+1] = dp[i] + dp[i-1];
            else
                dp[i+1] = dp[i];
        }
        return dp[s.size()];
    }
};