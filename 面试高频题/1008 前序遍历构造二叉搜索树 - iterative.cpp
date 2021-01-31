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
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.emplace(root);
        for (int i=1; i<preorder.size(); ++i) {
            TreeNode* cur = new TreeNode(preorder[i]);
            TreeNode* top = stk.top();
            while (!stk.empty() && cur->val > stk.top()->val) {
                top = stk.top();
                stk.pop();
            }
            if (cur->val > top->val)
                top->right = cur;
            else
                top->left = cur;
            stk.emplace(cur);
        }
        return root;
    }
};