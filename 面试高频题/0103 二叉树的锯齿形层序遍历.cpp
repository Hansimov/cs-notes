class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool need_reverse = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size--) {
                TreeNode* t = q.front();
                v.push_back(t->val);
                q.pop();

                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            if (need_reverse)
                reverse(v.begin(), v.end());
            res.push_back(v);
            need_reverse = !need_reverse;
        }
        return res;
    }
};