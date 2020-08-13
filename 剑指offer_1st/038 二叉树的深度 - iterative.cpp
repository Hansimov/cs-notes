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
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot==NULL) return 0;
        queue<TreeNode*> q;
        TreeNode *t;
        int depth = 0;
        q.push(pRoot);
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ++depth;
        }
        return depth;
    }
};