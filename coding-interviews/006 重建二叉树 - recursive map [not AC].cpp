/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int> &pre, vector<int> &vin, int ib, int ie, unordered_map<int,int> &in_map) {
        static int pre_idx = 0;
        if (ib>ie)
            return NULL;
        int val = pre[pre_idx];
        TreeNode *t = new TreeNode(val);
        ++pre_idx;

        if (ib==ie)
            return t;

        int in_idx = in_map[val];

        t->left  = helper(pre, vin, ib, in_idx-1, in_map);
        t->right = helper(pre, vin, in_idx+1, ie, in_map);
        return t;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        unordered_map<int,int> in_map;
        for (int i=0; i<vin.size(); ++i)
            in_map[vin[i]] = i;
        return helper(pre, vin, 0, vin.size()-1, in_map);
    }
};