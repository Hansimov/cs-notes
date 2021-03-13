#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        K = min(n/2, K);
        vector<vector<int>> keep(n, vector<int>(K+1,0));
        vector<vector<int>> sold(n, vector<int>(K+1,0));

        keep[0][0] = -prices[0];
        sold[0][0] = 0;
        for (int i=1; i<n; ++i)
            keep[i][0] = max(keep[i-1][0], -prices[i]);

        for (int j=1; j<=K; ++j) {
            keep[0][j] = INT_MIN/2;
            sold[0][j] = INT_MIN/2;
        }

        for (int i=1; i<n; ++i) {
            for (int j=1; j<=K; ++j) {
                keep[i][j] = max(keep[i-1][j], sold[i-1][j] - prices[i]);
                sold[i][j] = max(sold[i-1][j], keep[i-1][j-1] + prices[i]);
            }
        }

        return *max_element(sold[n-1].begin(), sold[n-1].end());
    }
};

int main() {
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    // vector<int> prices = {2,4,1};
    Solution sol;
    cout << sol.maxProfit(k, prices) << endl;
    
    return 0;
}