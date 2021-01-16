class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(int k, int target, int cur) {
        if ( (temp.size() + (9-cur+1) < k) || temp.size() > k)
            return ;
        if (temp.size() == k && target == 0) {
            res.push_back(temp);
            return ;
        }

        // not choose cur
        dfs(k, target, cur+1);

        // choose cur
        temp.push_back(cur);
        dfs(k, target-cur, cur+1);
        temp.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
};