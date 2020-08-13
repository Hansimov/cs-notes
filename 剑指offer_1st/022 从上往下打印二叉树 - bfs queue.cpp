/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root==NULL) return {};

        vector<int> v;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *t;
        while (!q.empty()) {
            t = q.front();
            v.push_back(t->val);
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        
        return v;
    }
};