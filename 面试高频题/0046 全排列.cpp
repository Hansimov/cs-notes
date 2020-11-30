/*
* 【46】C++ 回溯法/交换法/stl 简洁易懂的全排列 - 全排列 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/permutations/solution/c-hui-su-fa-jiao-huan-fa-stl-jian-ji-yi-dong-by-sm/
*/
class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, vector<int> &current, vector<bool> &flags) {
        if (current.size() == flags.size()) {
            res.push_back(current);
        } else {
            for (int i=0; i<nums.size(); ++i) {
                if (not flags[i]) { // nums[i] not in current
                    current.push_back(nums[i]);
                    flags[i] = true;
                    backtrack(nums, current, flags);
                    current.pop_back();
                    flags[i] = false;
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<bool> flags(nums.size(), false); // true: in current; false: not in current
        vector<int> current;
        backtrack(nums, current, flags);
        return res;
    }
};