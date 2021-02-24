class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int> dp(6*n+1, 0);
        for (int i=1; i<=6; ++i) {
            dp[i] = 1;
        }
        
        // i: row num; j: col idx; k: 1~6(max)
        for (int i=2; i<=n; ++i) {
            for (int j=6*i; j>=i; --j) {
                dp[j]=0;
                for (int k=1; k<=6 && j-k>=i-1; ++k) {
                    dp[j] += dp[j-k];
                }
            }
        }

        double div = pow(6,n);
        vector<double> res;
        for (int i=n; i<=6*n; ++i) {
            res.push_back(dp[i]*1.0 / div);
        }

        return res;
    }
};