/*

* 二叉搜索树与双向链表__牛客网 
    * https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5

* 三种解法_牛客博客 
    * https://blog.nowcoder.net/n/17c95de2427e49abb207a6a9d37c602d?f=comment

* Convert a given Binary Tree to Doubly Linked List | Set 1 - GeeksforGeeks 
    * https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
    void helper(TreeNode *cur, TreeNode* &pre) {
        if (cur==NULL) return ;
        helper(cur->left, pre);
        cur->left = pre;
        if (pre)
            pre->right = cur;
        pre = cur;
        helper(cur->right, pre);
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) return NULL;
        TreeNode *pre = NULL;
        helper(pRootOfTree, pre);

        // Reuse pre to avoid new TreeNode creation
        while (pre->left)
            pre = pre->left;
        return pre;
    }
};