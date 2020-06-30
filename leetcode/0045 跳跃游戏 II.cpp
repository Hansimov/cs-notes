/*

* 跳跃游戏 II - 跳跃游戏 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int tmp_max = 0;
        int step = 0;
        for (int i=0; i<nums.size()-1; ++i) {
            tmp_max = max(tmp_max, nums[i]+i);
            if (end == i) {
                ++step;
                end = tmp_max;
            }
        }
        return step;
    }
};