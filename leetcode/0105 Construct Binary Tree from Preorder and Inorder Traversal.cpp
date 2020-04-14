// * Python short recursive solution. - LeetCode Discuss 
// ** https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34579/Python-short-recursive-solution.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;

        
        int t = preorder[0];
        int mid = -1;
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i]==t) {
                mid = i;
                break;
            }
        }

        TreeNode * root;
        root = new TreeNode(t);

        preorder.erase(preorder.begin());

        if (mid<=0)
            root->left = NULL;
        else {
            vector<int> left = vector<int>(inorder.begin(),inorder.begin()+mid);
            root->left = buildTree(preorder,left);
        }

        if (mid+1>=inorder.size())
            root->right = NULL;
        else {
            vector<int>right = vector<int>(inorder.begin()+mid+1,inorder.end());
            root->right = buildTree(preorder,right);
        }

        return root;

    }
};