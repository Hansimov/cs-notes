// * 3-line c++ solution - LeetCode Discuss 
// ** https://leetcode.com/problems/sum-of-left-leaves/discuss/88976/3-line-c%2B%2B-solution

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL)
            return 0;
        int left_subtree_sum = 0;
        if (root->left!=NULL)
            if (root->left->left==NULL && root->left->right ==NULL)
                left_subtree_sum =  root->left->val;
            else
                left_subtree_sum = sumOfLeftLeaves(root->left);
        else
            left_subtree_sum = 0;

        return left_subtree_sum + sumOfLeftLeaves(root->right);
    }
};