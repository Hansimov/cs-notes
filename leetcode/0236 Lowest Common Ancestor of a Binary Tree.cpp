// * 【236. 二叉树的最近公共祖先】简洁代码 - 二叉树的最近公共祖先 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-jian-j/

// * 4 lines C++/Java/Python/Ruby - LeetCode Discuss 
// ** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65225/4-lines-C%2B%2BJavaPythonRuby

// * 二叉树的最近公共祖先 - 二叉树的最近公共祖先 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetcod/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root->val==p->val || root->val==q->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if (left!=NULL && right!=NULL)
            return root;
        if (left!=NULL)
            return left;
        else
            return right;

    }
};