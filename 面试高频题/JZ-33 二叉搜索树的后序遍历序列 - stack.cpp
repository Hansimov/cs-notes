class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stk;
        int root = INT_MAX;
        for (int i=postorder.size()-1; i>=0; --i) {
            int cur = postorder[i];
            while (!stk.empty() && cur<stk.top()) {
                root = stk.top();
                stk.pop();
            }
            if (cur>root) {
                return false;
            }
            stk.push(cur);
        }

        return true;
    }
};