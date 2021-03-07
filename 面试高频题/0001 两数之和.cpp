class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n<=1)
            return {};

        unordered_map<int, int> map;
        for (int i=0; i<n; ++i) {
            auto itr = map.find(target-nums[i]);
            if (itr != map.end())
                return {itr->second, i};
            else
                map[nums[i]] = i;
        }
        return {};
    }
};