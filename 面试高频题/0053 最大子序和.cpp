class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int res = nums[0];
        int pre = 0;
        for (auto const &x : nums) {
            pre = max(pre+x, x);
            res = max(res, pre);
        }
        return res;
    }
};