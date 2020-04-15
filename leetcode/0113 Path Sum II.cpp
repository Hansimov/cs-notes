// * 12ms 11-lines C++ Solution - LeetCode Discuss 
// ** https://leetcode.com/problems/path-sum-ii/discuss/36685/12ms-11-lines-C%2B%2B-Solution

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
    void findPaths(TreeNode* t, int sum, vector<int>& path, vector<vector<int>>& paths) {
        if (t==NULL)
            return;
        int val = t->val;
        path.push_back(val);

        if (val==sum && t->left==NULL && t->right==NULL) {
            paths.push_back(path);
        }

        findPaths(t->left, sum-val, path, paths);
        findPaths(t->right, sum-val, path, paths);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        findPaths(root,sum,path,paths);
        return paths;
    }
};