class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(vector<int> & candidates, int target, int idx) {
        if (idx==candidates.size())
            return ;
        if (target==0) {
            res.push_back(temp);
            return ;
        }
        
        // This part must be after the previous part
        if (target - candidates[idx] < 0) {
            return ;
        }

        // do not choose candidates[idx]
        dfs(candidates, target, idx+1);

        // choose candidates[idx]
        temp.push_back(candidates[idx]);
        dfs(candidates, target-candidates[idx], idx);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
};