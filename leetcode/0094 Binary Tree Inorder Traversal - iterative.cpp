/**
* C++ Iterative, Recursive and Morris - LeetCode Discuss 
    * https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris
* Inorder Tree Traversal without Recursion - GeeksforGeeks 
    * https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
* Iterative Inorder Traversal of Binary Tree - YouTube 
    * https://www.youtube.com/watch?v=nzmtCFNae9k

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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *t = root;

        while(!s.empty() || t!=NULL) {
            while(t!=NULL) {
                s.push(t);
                t = t->left;
            }

            t = s.top();
            s.pop();
            v.push_back(t->val);
            t = t->right;
        }
        return v;
    }
};