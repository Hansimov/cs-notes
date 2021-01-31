/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (idx == preorder.size() || preorder[idx] < left || preorder[idx] > right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = helper(preorder, left, root->val);
        root->right = helper(preorder, root->val, right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MIN, INT_MAX);
    }
};