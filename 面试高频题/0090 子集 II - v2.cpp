class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void backtrack(int cur, vector<int> &nums) {
        // not choose nums[cur]
        res.push_back(temp);

        // maybe choose nums[cur]
        for (int i=cur; i<nums.size(); ++i) {
            if (i>cur && nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            backtrack(i+1, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return res;
    }
};