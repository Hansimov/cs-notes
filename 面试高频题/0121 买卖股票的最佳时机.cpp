class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0)
            return 0;
        int min_price = prices[0];
        vector<int> dp(n,0);
        for (int i=1; i<n; ++i) {
            min_price = min(min_price, prices[i]);
            dp[i] = max(dp[i-1], prices[i]-min_price);
        }
        return dp[n-1];
    }
};