// * C++ Recursive and Iterative - LeetCode Discuss 
// ** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/discuss/64980/C%2B%2B-Recursive-and-Iterative

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};