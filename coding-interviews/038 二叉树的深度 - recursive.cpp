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
        int left_depth = TreeDepth(pRoot->left);
        int right_depth = TreeDepth(pRoot->right);
        return max(left_depth,right_depth)+1;
    }
};