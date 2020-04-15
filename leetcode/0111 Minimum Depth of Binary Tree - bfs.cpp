// * BFS（递归/迭代） - 二叉树的最小深度 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/bfsdi-gui-die-dai-by-24shi-01fen-_00_01/

// * BFS, C++, 8ms, Beats 99.94% submissions - LeetCode Discuss 
// ** https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/36071/BFS-C++-8ms-Beats-99.94-submissions


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
    int minDepth(TreeNode* root) {
        if (root==NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;
        while (!q.empty()) {
            depth++;
            int layer_size = q.size();
            for (int i=0; i<layer_size; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left==NULL && t->right==NULL)
                    return depth;
                if (t->left!=NULL)
                    q.push(t->left);
                if (t->right!=NULL)
                    q.push(t->right);
            }
        }

        return depth;
    }
};