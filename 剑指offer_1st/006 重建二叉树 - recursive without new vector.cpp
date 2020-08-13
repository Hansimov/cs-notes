/**

* Clear and easy c++ solution - LeetCode Discuss 
    * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34675/Clear-and-easy-c%2B%2B-solution

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* helper(vector<int> &pre, vector<int> &vin, int pre_ptr, int in_beg, int in_end) {
        if (in_beg > in_end)
            return NULL;
        TreeNode *t = new TreeNode(pre[pre_ptr]);
        int in_ptr = find(vin.begin()+in_beg, vin.begin()+in_end+1, t->val) - vin.begin();
        int left_tree_size = in_ptr - in_beg;
        t->left  = helper(pre, vin, pre_ptr+1,                in_beg,   in_ptr-1);
        t->right = helper(pre, vin, pre_ptr+left_tree_size+1, in_ptr+1, in_end);
        return t;
    }

public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty())
            return NULL;
        return helper(pre, vin, 0, 0, vin.size()-1);
    }
};