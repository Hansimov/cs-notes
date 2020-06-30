/*

* 跳跃游戏 - 跳跃游戏 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        int tmp_max = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (i<=tmp_max) {
                tmp_max = max(tmp_max, nums[i]+i);
                if (tmp_max >= nums.size()-1) {
                    return true;
                }
            }
        }
        return false;
    }
};