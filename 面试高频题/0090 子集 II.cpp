class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void backtrack(int cur, vector<int> &nums, vector<bool> &used) {
        // not choose nums[cur]
        res.push_back(temp);

        // maybe choose nums[cur]
        for (int i=cur; i<nums.size(); ++i) {
            if (i>0 && nums[i]==nums[i-1] && !used[i-1])
                continue;
            temp.push_back(nums[i]);
            used[i] = true;
            backtrack(i+1, nums, used);
            used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(0, nums, used);
        return res;
    }
};