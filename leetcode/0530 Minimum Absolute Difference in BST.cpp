// * 中序遍历团灭系列二叉搜索树问题 - 二叉搜索树的最小绝对差 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/solution/zhong-xu-bian-li-tuan-mie-xi-lie-er-cha-sou-suo-sh/

// * 中序遍历并比较相邻遍历节点 - 二叉搜索树的最小绝对差 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/solution/zhong-xu-bian-li-bing-bi-jiao-xiang-lin-bian-li-ji/

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
    void inorder(TreeNode *root, int &pre_val, int &res) {
        if (!root) return;

        inorder(root->left, pre_val, res);

        if (pre_val>=0) {
            int cur_diff = abs(root->val - pre_val);
                if (cur_diff < res) {
                    res = cur_diff;
                }
        }
        pre_val = root->val;

        inorder(root->right, pre_val, res);
    }

    int getMinimumDifference(TreeNode *root) {
        int pre_val = -1;
        int res = INT_MAX;
        inorder(root,pre_val,res);
        return res;
    }
};