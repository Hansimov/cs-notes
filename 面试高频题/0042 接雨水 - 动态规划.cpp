class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int n = height.size();

        vector<int> L_max(n,0);
        for (int i=1; i<n; ++i)
            L_max[i] = max(L_max[i-1], height[i-1]);
        
        vector<int> R_max(n,0);
        for (int i=n-2; i>=0; --i)
            R_max[i] = max(R_max[i+1], height[i+1]);
        
        int res = 0;
        for (int i=0; i<n; ++i)
            res += max(0, min(L_max[i], R_max[i])-height[i]);

        return res;
    }
};