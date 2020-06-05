/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 [1,2,3,4,5,null,null,null,null,6,7]
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        stack<TreeNode *> s;
        vector<int> v;
        s.push(root);
        TreeNode *t;
        while(!s.empty()) {
            t = s.top();
            v.push_back(t->val);
            s.pop();
            if (t->right!=NULL)
                s.push(t->right);
            if (t->left!=NULL)
                s.push(t->left);
        }
        return v;
    }
};