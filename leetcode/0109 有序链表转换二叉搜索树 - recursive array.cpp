/**

* 有序链表转换二叉搜索树 - 有序链表转换二叉搜索树 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-by-/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    TreeNode* vectorToBST(vector<int> &v, int left, int right) {
        if (left==right)
            return NULL;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = vectorToBST(v,left, mid);
        root->right = vectorToBST(v,mid+1,right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        return vectorToBST(v, 0, v.size());
    }
};