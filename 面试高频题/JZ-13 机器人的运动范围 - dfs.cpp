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

    int dfs(int m, int n, int k, int i, int j, vector<vector<bool>>& visited) {
        if (i>=m || j>=n || visited[i][j] || digitSum(i)+digitSum(j)>k)
            return 0;
        visited[i][j] = true;
        return 1 + dfs(m, n, k, i+1, j, visited) + dfs(m, n, k, i, j+1, visited);
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(m, n, k, 0, 0, visited);
    }
};