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
    bool isEqual(TreeNode *l_node, TreeNode *r_node) {
        if (l_node==NULL || r_node==NULL)
            return l_node == r_node;
        if (l_node->val != r_node->val)
            return false;
        return isEqual(l_node->left, r_node->right) && isEqual(l_node->right, r_node->left);
    }
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot==NULL) return true;

        return isEqual(pRoot->left, pRoot->right);
    }
};