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
        TreeNode *cur = root, *last=NULL, *top=NULL;
        vector<int> v;
        stack<TreeNode *> s;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                top = s.top();
                if (top->right && top->right != last) {
                    cur = top->right;
                } else {
                    v.push_back(top->val);
                    last = top;
                    s.pop();
                }
            }
        }
        return v;
    }
};