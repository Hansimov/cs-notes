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
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            if (pRoot==NULL) return {};
            vector<vector<int>> res;
            queue<TreeNode*> q;
            TreeNode *t;
            q.push(pRoot);
            while (!q.empty()) {
                vector<int> v;
                int q_size = q.size();
                while (q_size--) {
                    t = q.front();
                    q.pop();
                    v.push_back(t->val);
                    if (t->left)
                        q.push(t->left);
                    if (t->right)
                        q.push(t->right);
                }
                res.push_back(v);
            }
            return res;
        }
    
};