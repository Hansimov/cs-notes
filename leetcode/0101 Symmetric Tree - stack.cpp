// * Recursive and non-recursive solutions in Java - LeetCode Discuss 
// ** https://leetcode.com/problems/symmetric-tree/discuss/33054/Recursive-and-non-recursive-solutions-in-Java/31849

// * My C++ Accepted code in 16ms with iteration solution - LeetCode Discuss 
// ** https://leetcode.com/problems/symmetric-tree/discuss/33089/My-C%2B%2B-Accepted-code-in-16ms-with-iteration-solution

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        stack<TreeNode*> stk;

        stk.push(root->left);
        stk.push(root->right);
        while (!stk.empty()) {
            TreeNode* node1 = stk.top();
            stk.pop();
            TreeNode* node2 = stk.top();
            stk.pop();

            if (node1==NULL && node2==NULL)
                continue;
            if (node1==NULL || node2==NULL)
                return false;
            if (node1->val != node2->val)
                return false;
            stk.push(node1->left);
            stk.push(node2->right);
            stk.push(node1->right);
            stk.push(node2->left);
        }

        return true;
    }
};