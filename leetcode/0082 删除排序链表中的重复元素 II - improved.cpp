/**

* 超清晰图解（三指针法） - 删除排序链表中的重复元素 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/chao-qing-xi-tu-jie-san-zhi-zhen-fa-by-justdo1t/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        ListNode *left, *right;
        while (cur->next) {
            left = cur->next;
            right = cur->next;
            while (right->next && right->next->val == left->val)
                right = right->next;
            if (left==right) {
                cur = cur->next;
            } else {
                cur->next = right->next;
                while (left!=right) {
                    ListNode *tmp = left;
                    left = left->next;
                    delete tmp;
                }
                delete left;
            }
        }

        return dummyHead->next;
    }
};