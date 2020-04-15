

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int depth(TreeNode *t) {
        if (t==NULL)
            return 0;
        return max(depth(t->left),depth(t->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
            return true;

        int left_depth = depth(root->left);
        int right_depth = depth(root->right);

        return abs(left_depth-right_depth)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};