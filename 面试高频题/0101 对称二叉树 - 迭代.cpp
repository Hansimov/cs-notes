class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            auto L = q.front();
            q.pop();
            auto R = q.front();
            q.pop();
            if (L==nullptr && R==nullptr)
                continue;
            if (L==nullptr || R==nullptr)
                return false;
            if (L->val != R->val)
                return false;
            q.push(L->left);
            q.push(R->right);
            q.push(L->right);
            q.push(R->left);
        }
        return true;
    }
};