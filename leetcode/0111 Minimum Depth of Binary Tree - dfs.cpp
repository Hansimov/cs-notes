// * 二叉树的最小深度-理解递归结束条件 - 二叉树的最小深度 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/li-jie-zhe-dao-ti-de-jie-shu-tiao-jian-by-user7208/

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
    int minDepth(TreeNode* root) {
        if (root==NULL)
            return 0;

        if (root->left==NULL && root->right==NULL)
            return 1;

        if (root->left==NULL)
            return minDepth(root->right)+1;
        if (root->right==NULL)
            return minDepth(root->left)+1;

        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};