// * C++ simple 4ms recursive solution - LeetCode Discuss 
// ** https://leetcode.com/problems/binary-tree-paths/discuss/68270/C%2B%2B-simple-4ms-recursive-solution

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
    void helper(vector<string>& res, TreeNode* t, string s) {
        if (t!=NULL)
            s += to_string(t->val);

        if (t->left==NULL && t->right==NULL) {
            res.push_back(s);
            return ;
        } else {
            s += "->";
        }

        if (t->left!=NULL)
            helper(res, t->left, s);
        if (t->right!=NULL)
            helper(res, t->right, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if (root==NULL)
            return res;

        helper(res, root, "");
        return res;
    }
};