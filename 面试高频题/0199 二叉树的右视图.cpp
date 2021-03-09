class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode * t = q.front();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                q.pop();
                if (size==0)
                    res.push_back(t->val);
            }
        }
        return res;
    }
};