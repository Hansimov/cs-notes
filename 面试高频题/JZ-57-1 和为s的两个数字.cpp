class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int sum = 0;
        while (left < right) {
            sum = nums[left] + nums[right];
            if (sum == target)
                return vector<int>{nums[left], nums[right]};
            else if (sum < target)
                ++left;
            else
                --right;
        }
        return {};
    }
};