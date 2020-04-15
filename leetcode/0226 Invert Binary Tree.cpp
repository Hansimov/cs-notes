// * Recursive and non-recursive C++ both 4ms - LeetCode Discuss 
// ** https://leetcode.com/problems/invert-binary-tree/discuss/62731/Recursive-and-non-recursive-C%2B%2B-both-4ms

// * Straightforward DFS recursive, iterative, BFS solutions - LeetCode Discuss 
// ** https://leetcode.com/problems/invert-binary-tree/discuss/62707/Straightforward-DFS-recursive-iterative-BFS-solutions

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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)
            return NULL;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};