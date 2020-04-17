// * 详细通俗的思路分析，多解法 - 二叉搜索树中第K小的元素 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--48/

// * 中序遍历(生成器)+提前终止 - 二叉搜索树中第K小的元素 - 力扣（LeetCode） 
// ** https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/zhong-xu-bian-li-sheng-cheng-qi-ti-qian-zhong-zhi-/

// * 4 Lines in C++. - LeetCode Discuss 
// ** https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/63673/4-Lines-in-C%2B%2B.

// * 3 ways implemented in JAVA (Python): Binary Search, in-order iterative & recursive - LeetCode Discuss 
// ** https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/63660/3-ways-implemented-in-JAVA-(Python)%3A-Binary-Search-in-order-iterative-and-recursive

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
    int kthSmallest(TreeNode* root, int& k) {
        if (root==NULL)
            return 0;

        int num = kthSmallest(root->left,k);
        if (k==0) {
            return num;
        } else {
            if (--k==0) {
                return root->val;
            } else {
                return kthSmallest(root->right,k);
            }
        }
    }
};