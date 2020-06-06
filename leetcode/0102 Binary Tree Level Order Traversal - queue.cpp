// * Leetcode 102. 二叉树的层次遍历 C++_C/C++_Hunter的博客-CSDN博客 
// ** https://blog.csdn.net/yuanliang861/article/details/83216783

// * 二叉树的层序遍历 - 二叉树的层序遍历 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-de-ceng-xu-bian-li-by-leetcode-solution/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v_v = {};
        if (root == NULL)
            return {};
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> v = {};

            while (size--) {
                TreeNode *tmp = q.front();
                v.push_back(tmp->val);
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
                q.pop();
            }
            v_v.push_back(v);
        }
        return v_v;
    }
};