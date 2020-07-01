/*

* 分发糖果 - 分发糖果 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size()==0)
            return 0;

        vector<int> nums(ratings.size(), 1);

        for (int i=1; i<nums.size(); ++i) {
            if (ratings[i]>ratings[i-1])
                nums[i] = nums[i-1] + 1;
        }
        for (int i=nums.size()-2; i>=0; --i) {
            if (ratings[i]>ratings[i+1]) {
                nums[i] = max(nums[i], nums[i+1]+1);
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};