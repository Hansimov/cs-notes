class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto const& ele: nums)
            res ^= ele;
        return res;
    }
};