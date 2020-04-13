// * My code of C++, Depth-first-search and Breadth-first-search - LeetCode Discuss 
// ** https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/34207/My-code-of-C%2B%2B-Depth-first-search-and-Breadth-first-search

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
    int maxDepth(TreeNode* root) {
        return root==NULL ? 0 : max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};