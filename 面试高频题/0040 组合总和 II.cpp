class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(vector<int>& candidates, int target, int idx) {
        if (target==0) {
            res.push_back(temp);
            return ;
        }

        for (int i=idx; i<candidates.size(); ++i) {
            if (target - candidates[idx] < 0)
                break;
            if (i>idx && candidates[i] == candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
};