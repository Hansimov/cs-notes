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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree==NULL) return NULL;
        stack<TreeNode*> s;
        TreeNode *cur = pRootOfTree;
        TreeNode *pre = NULL;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cur->left = pre;
            if (pre)
                pre->right = cur;
            pre = cur;
            cur = cur->right;
        }

        while (pre->left)
            pre = pre->left;

        return pre;
    }
};