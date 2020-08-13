class Solution {
    int get_depth(TreeNode* t) {
        if (t==NULL) return 0;
        int left_depth = get_depth(t->left);
        if (left_depth == -1)
            return -1;
        int right_depth = get_depth(t->right);
        if (right_depth == -1)
            return -1;
        return abs(left_depth-right_depth) > 1 ? -1 : max(left_depth,right_depth)+1;
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return get_depth(pRoot) != -1;
    }
};