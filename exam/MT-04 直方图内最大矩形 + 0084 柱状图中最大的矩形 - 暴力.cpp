class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int L, R;
        int res=0;
        for (int i=0; i<heights.size(); ++i) {
            L = i;
            R = i;
            while (L>=0 && heights[L]>=heights[i])
                --L;
            while (R<heights.size() && heights[R]>=heights[i])
                ++R;
            res = max(res, heights[i]*(R-L-1));
        }
        return res;
    }
};