class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode*root, int sum) {
        if (!root) return;

        path.push_back(root->val);
        sum -= root->val;

        if (sum==0 && root->left==nullptr && root->right==nullptr) {
            res.push_back(path);
        }

        dfs(root->left,  sum);
        dfs(root->right, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};