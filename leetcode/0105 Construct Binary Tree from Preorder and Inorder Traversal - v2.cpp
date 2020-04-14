// * Construct Binary Tree from Preorder and Inorder Traversal - Submission Detail - LeetCode 
// ** https://leetcode.com/submissions/detail/324462229/

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

    TreeNode* helper(vector<int>& preorder, int pre_start, vector<int>& inorder, int in_start, int in_end, unordered_map<int,int>& in_map) {

        if (pre_start>=preorder.size() || in_start>in_end) 
            return NULL;

        int t_val = preorder[pre_start];
        TreeNode* t = new TreeNode(t_val);
        int mid = in_map[t_val];

        t->left = helper(preorder, pre_start+1, inorder, in_start, mid-1, in_map);
        t->right = helper(preorder, pre_start+(mid-in_start)+1, inorder, mid+1, in_end, in_map);

        return t;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> in_map;
        for (int i=0; i<inorder.size(); i++) {
            in_map[inorder[i]] = i;
        }

        return helper(preorder, 0, inorder, 0, inorder.size()-1, in_map);
    }
};