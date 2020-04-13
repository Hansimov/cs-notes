// * Recursive and non-recursive solutions in Java - LeetCode Discuss 
// ** https://leetcode.com/problems/symmetric-tree/discuss/33054/Recursive-and-non-recursive-solutions-in-Java

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        else
            return isSymmetricHelp(root->left, root->right);
    }
    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
        if (left==NULL || right==NULL)
            return left == right;
        else
            if (left->val != right->val)
                return false;
            else
                return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(right->left,left->right);
    }
};