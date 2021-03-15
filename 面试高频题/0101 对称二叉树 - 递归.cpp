class Solution {
public:
    bool helper(TreeNode* L, TreeNode* R) {
        if (L==nullptr && R==nullptr)
            return true;
        if (L==nullptr || R==nullptr)
            return false;
        return (L->val == R->val) && helper(L->left, R->right) && helper(L->right, R->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root==nullptr)
            return true;
        else
            return helper(root->left, root->right);
    }
};