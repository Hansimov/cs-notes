// * [c++] 5ms version: one queue and without reverse operation by using size of each level - LeetCode Discuss 
// ** https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/33825/c%2B%2B-5ms-version%3A-one-queue-and-without-reverse-operation-by-using-size-of-each-level

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==NULL)
            return {};
        vector<vector<int>> v_v = {};
        queue<TreeNode *> q;
        q.push(root);

        bool isForwards = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> v = {};
            while(size--) {
                TreeNode *t = q.front();
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
                v.push_back(t->val);
                q.pop();
            }
            if (!isForwards)
                reverse(v.begin(), v.end());
            v_v.push_back(v);
            isForwards = !isForwards;
        }

        return v_v;
    }
};