class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x!=0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        if (k==0)
            return 1;
        int res = 1;
        vector<vector<int>> reachable(m, vector<int>(n, 0));
        reachable[0][0] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if ( (i==0 && j==0) || digitSum(i)+digitSum(j)>k)
                    continue;
                if (i>=1)
                    reachable[i][j] |= reachable[i-1][j];
                if (j>=1)
                    reachable[i][j] |= reachable[i][j-1];
                res += reachable[i][j];
            }
        }
        return res;
    }
};