class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return {};
        vector<int> res(n, 1);
        // multiply numsll elements left of current idx
        for (int i=1; i<n; ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        // multiply numsll elements right of current idx
        int R = 1;
        for (int i=n-1; i>=0; --i) {
            res[i] *= R;
            R *= nums[i];
        }
        return res;
    }
};