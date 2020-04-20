// * 二叉搜索树中的众数 - 二叉搜索树中的众数 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/solution/er-cha-sou-suo-shu-zhong-de-zhong-shu-by-junstat/

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        TreeNode *pre = NULL;
        int cur_cnt = 1, max_cnt = 0;
        inorder(root,pre,cur_cnt,max_cnt,res);
        return res;
    }

    void inorder(TreeNode *root, TreeNode* &pre, int &cur_cnt, int &max_cnt, vector<int> &res) {
        if (root==NULL)
            return ;
        inorder(root->left, pre, cur_cnt, max_cnt, res);

        if (pre!=NULL)
            if (root->val == pre->val)
                cur_cnt += 1;
            else 
                cur_cnt = 1;

        if (cur_cnt == max_cnt)
            res.push_back(root->val);
        else if (cur_cnt > max_cnt) {
            res.clear();
            res.push_back(root->val);
            max_cnt = cur_cnt;
        }

        pre = root;

        inorder(root->right, pre, cur_cnt, max_cnt, res);
    }
};