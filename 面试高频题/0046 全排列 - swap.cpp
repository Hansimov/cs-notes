/*
* 【46】C++ 回溯法/交换法/stl 简洁易懂的全排列 - 全排列 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/permutations/solution/c-hui-su-fa-jiao-huan-fa-stl-jian-ji-yi-dong-by-sm/
* 全排列 - 全排列 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
*/
class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int start, int end) {
        if (start == end) {
            res.push_back(nums);
        } else {
            for (int i=start; i<=end; ++i) {
                swap(nums[i], nums[start]);
                backtrack(nums, start+1, end);
                swap(nums[i], nums[start]);
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        } else {
            backtrack(nums, 0, nums.size()-1);
            return res;
        }
    }
};