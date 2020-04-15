// * The bottom up O(N) solution would be better - LeetCode Discuss 
// ** https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better

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

        int left_d = depth(t->left);
        if (left_d==-1)
            return -1;

        int right_d = depth(t->right);
        if (right_d==-1)
            return -1;

        if (abs(left_d-right_d)>1)
            return -1;

        return max(left_d,right_d)+1;
    }

    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};