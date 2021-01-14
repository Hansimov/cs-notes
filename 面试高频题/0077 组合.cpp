class Solution {
public:
    vector<vector<int>> res;   // result 2d vector
    vector<int> temp;          // temp vector path

    void dfs(int cur, int n, int k) {
    // cur: current element index, choose or not
        if (temp.size() + (n - cur + 1) < k)
            return ;
        if (temp.size() == k) {
            res.push_back(temp);
            return ;
        }

        // choose cur
        temp.push_back(cur);
        dfs(cur+1, n, k);
        temp.pop_back();

        // do not choose cur
        dfs(cur+1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};