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
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(pRoot);
        bool to_reverse = false;
        TreeNode *t;
        while (!q.empty()) {
            int q_size = q.size();
            vector<int> v;
            while(q_size--) {
                t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            if (to_reverse)
                reverse(v.begin(), v.end());
            to_reverse = !to_reverse;
            res.push_back(v);
        }
        return res;
    }
    
};