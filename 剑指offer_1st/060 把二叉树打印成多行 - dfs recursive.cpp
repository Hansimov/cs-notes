/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
        void helper(vector<vector<int>> &res, TreeNode *t, int level) {
            if (t==NULL) return ;
            if (level>=res.size())
                res.push_back(vector<int>{});
            res[level].push_back(t->val);
            helper(res, t->left, level+1);
            helper(res, t->right, level+1);
        }
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            if (pRoot==NULL) return {};
            vector<vector<int>> res;
            helper(res, pRoot, 0);
            return res;
        }
    
};