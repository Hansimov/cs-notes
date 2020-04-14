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
    TreeNode* helper(vector<int>& postorder, int post_end, vector<int>& inorder, int in_start, int in_end, unordered_map<int,int>& in_map) {

        if (post_end<0 || in_start>in_end)
            return NULL;

        int t_val = postorder[post_end];
        TreeNode* t = new TreeNode(t_val);
        int mid = in_map[t_val];

        t->left = helper(postorder, post_end-(in_end-mid)-1, inorder, in_start, mid-1, in_map);
        t->right = helper(postorder, post_end-1, inorder, mid+1, in_end, in_map);
        return t;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> in_map;
        for (int i=0; i<inorder.size(); i++) {
            in_map[inorder[i]] = i;
        }
        return helper(postorder, postorder.size()-1, inorder, 0, inorder.size()-1, in_map);
    }
};
