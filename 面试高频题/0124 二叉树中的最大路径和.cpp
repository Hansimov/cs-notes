class Solution {
public:
    int res=INT_MIN;

    int maxGain(TreeNode* root) {
        if (!root) return 0;

        int L_gain = max(maxGain(root->left),0);
        int R_gain = max(maxGain(root->right),0);

        res = max(res, root->val + L_gain + R_gain);
        return root->val + max(L_gain, R_gain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return res;
    }
};