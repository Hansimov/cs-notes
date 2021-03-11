// class Solution {
// public:
    // int largestRectangleArea(vector<int>& heights) {
class MaxInnerRec {
public:
    int countArea(vector<int> &heights, int n) {
        if (heights.empty()) return 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int sz = heights.size();

        int res = 0;
        stack<int> s;
        s.push(0);
        for (int i=1; i<sz; ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int L_idx = s.top();
                int R_idx = i;
                res = max(res, height * (R_idx-L_idx-1));
            }
            s.push(i);
        }
        return res;
    }
};