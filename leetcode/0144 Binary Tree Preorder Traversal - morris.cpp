/**

* Morris traversal for Preorder - GeeksforGeeks 
    * https://www.geeksforgeeks.org/morris-traversal-for-preorder/

前 2 1 1 3 2

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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        vector<int> v;
        TreeNode *cur = root;
        TreeNode *pre;
        while (cur!=NULL) {
            if (cur->left==NULL) {
                v.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right!=NULL && pre->right!=cur) {
                    pre = pre->right;
                }
                if (pre->right==NULL) {
                    v.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return v;
    }
};