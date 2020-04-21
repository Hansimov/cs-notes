// * 二叉搜索树的范围和 - 二叉搜索树的范围和 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/range-sum-of-bst/solution/er-cha-sou-suo-shu-de-fan-wei-he-by-leetcode/

// * 二叉树遍历的三种方法的非递归版本 - 简书 
// ** https://www.jianshu.com/p/1bfeedd54eaa

// * Inorder Tree Traversal without Recursion - GeeksforGeeks 
// ** https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

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
    int rangeSumBST(TreeNode *root, int L, int R) {
        int sum = 0;
        stack<TreeNode*> stk;

        TreeNode *t = root;

        while (t!=nullptr || !stk.empty()) {
            while (t!=nullptr) {
                stk.push(t);
                t = t->left;
            }
            t = stk.top();
            stk.pop();
            if (t->val > R)
                break;
            if (t->val >= L)
                sum += t->val;
            t = t->right;
        }

        return sum;
    }
};