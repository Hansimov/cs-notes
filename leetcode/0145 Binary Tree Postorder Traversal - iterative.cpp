/**
* C++ Iterative, Recursive and Morris Traversal - LeetCode Discuss 
    * https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45550/C%2B%2B-Iterative-Recursive-and-Morris-Traversal

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode *t;
        s.push(root);
        while (!s.empty()) {
            t = s.top();
            v.push_back(t->val);
            s.pop();
            if (t->left!=NULL)
                s.push(t->left);
            if (t->right!=NULL)
                s.push(t->right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};