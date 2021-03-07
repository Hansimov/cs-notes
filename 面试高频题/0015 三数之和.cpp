class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n < 3)
            return {};
        vector<vector<int>> res;
        int L, R;
        int sum;
        for (int i=0; i<n-2; ++i) {
            if (nums[i] > 0)
                break;
            if (i>0 && nums[i]==nums[i-1])
                continue;
            L = i+1;
            R = n-1;
            while (L<R) {
                sum = nums[i] + nums[L] + nums[R];
                if (sum<0) {
                    ++L;
                    while (L<R && nums[L]==nums[L-1])
                        ++L;
                } else if (sum>0) {
                    --R;
                    while (L<R && nums[R]==nums[R+1])
                        --R;
                } else {
                    res.push_back({nums[i], nums[L], nums[R]});
                    ++L;
                    --R;
                    while (L<R && nums[L]==nums[L-1])
                        ++L;
                    while (L<R && nums[R]==nums[R+1])
                        --R;
                }
            }
        }
        return res;
    }
};