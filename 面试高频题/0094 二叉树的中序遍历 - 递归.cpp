class Solution {
public:
    void recur(TreeNode* root, vector<int>& res) {
        if (root==nullptr) return;
        recur(root->left, res);
        res.push_back(root->val);
        recur(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        recur(root, res);
        return res;
    }
};