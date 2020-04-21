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
    void inorder(TreeNode *root, int L, int R, int &sum) {
        if (!root) return;

        inorder(root->left, L, R, sum);

        if (root->val > R)
            return;
        if (root->val >= L)
            sum += root->val;

        inorder(root->right, L, R, sum);

    }

    int rangeSumBST(TreeNode *root, int L, int R) {
        int sum = 0;
        inorder(root, L, R, sum);
        return sum;
    }
};