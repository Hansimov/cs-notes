class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int res = 0;
        int L = 0, R = height.size()-1;
        int L_max = 0, R_max = 0;
        while (L<=R) {
            if (L_max <= R_max) {
                res += max(0, L_max-height[L]);
                L_max = max(L_max, height[L]);
                ++L;
            } else {
                res += max(0, R_max-height[R]);
                R_max = max(R_max, height[R]);
                --R;
            }
        }
        return res;
    }
};