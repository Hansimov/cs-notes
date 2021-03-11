class Visit {
public:
    int countPath(vector<vector<int> > map, int n, int m) {
        // find 1 and 2
        int x1, y1, x2, y2;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (map[i][j]==1) {
                    x1 = i;
                    y1 = j;
                } else if (map[i][j]==2) {
                    x2 = i;
                    y2 = j;
                }
            }
        }
        // two man at same position
        if (x1==x2 && y1==y2)
            return 1;
        // set x1 as who has smaller row number
        if (x1>x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        // use dp
        vector<vector<int>> dp(n, vector<int>(m,0));
        // initialize firt column
        dp[x1][y1] = 1;
        for (int i=x1+1; i<=x2; ++i)  // top to bottom
            dp[i][y1] = (map[i][y1]==-1) ? 0 : dp[i-1][y1];
        // bi-direction
        if (y1<y2) { // left to right
            for (int j=y1+1; j<=y2; ++j)  // left to right
                dp[x1][j] = (map[x1][j]==-1) ? 0 : dp[x1][j-1];
            for (int i=x1+1; i<=x2; ++i) { // top-left to bottom-right
                for (int j=y1+1; j<=y2; ++j) {
                    dp[i][j] = (map[i][j]==-1) ? 0 : (dp[i-1][j] + dp[i][j-1]);
                }
            }
        } else { // right to left
            for (int j=y1-1; j>=y2; --j)
                dp[x1][j] = (map[x1][j]==-1) ? 0 : dp[x1][j+1];
            for (int i=x1+1; i<=x2; ++i) {
                for (int j=y1-1; j>=y2; --j) {
                    dp[i][j] = (map[i][j]==-1) ? 0 : (dp[i-1][j] + dp[i][j+1]);
                }
            }
        }

        return dp[x2][y2];
    }
};