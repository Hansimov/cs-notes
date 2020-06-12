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
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot==NULL) return true;
        stack<TreeNode *> s;

        s.push(pRoot->right);
        s.push(pRoot->left);
        while (!s.empty()) {
            TreeNode *l_node = s.top();
            s.pop();
            TreeNode *r_node = s.top();
            s.pop();
            if (l_node==NULL && r_node==NULL)
                continue;
            if (l_node==NULL || r_node==NULL)
                return false;
            if (l_node->val != r_node->val)
                return false;
            s.push(l_node->left);
            s.push(r_node->right);
            s.push(l_node->right);
            s.push(r_node->left);
        }
        return true;
    }
};