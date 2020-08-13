/*

* DFS非递归和递归python3 - 路径总和 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/path-sum-ii/solution/dfsfei-di-gui-python3-by-baiyizhe/

* Python solutions (Recursively, BFS+queue, DFS+stack) - LeetCode Discuss 
    * https://leetcode.com/problems/path-sum-ii/discuss/36829/Python-solutions-(Recursively-BFS%2Bqueue-DFS%2Bstack)


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
    void helper(TreeNode* t, int target, vector<int> &v, vector<vector<int>> &vv) {
        if (t==NULL) return;
        v.push_back(t->val);
        if (t->left==NULL && t->right==NULL && t->val == target) {
            vv.push_back(v);
        }
        helper(t->left, target-t->val, v, vv);
        helper(t->right, target-t->val, v, vv);
        v.pop_back();
    }
public:
    vector<vector<int>> FindPath(TreeNode* root, int sum) {
        if (root==NULL) return {};
        vector<vector<int>> vv;
        vector<int> v;
        helper(root, sum, v, vv);
        return vv;
    }
};