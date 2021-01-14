class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            res.push_back(temp);
            return ;
        }

        // choose nums[cur]
        temp.push_back(nums[cur]);
        dfs(cur+1, nums);
        temp.pop_back();

        // not choose nums[cur]
        dfs(cur+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};