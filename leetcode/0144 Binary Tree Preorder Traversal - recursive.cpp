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
private:
    void preorder(TreeNode* root, vector<int> &v) {
        if (root==NULL) return;
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right,v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        vector<int> v;
        preorder(root, v);
        return v;
    }
};