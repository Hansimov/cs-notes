/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* pre = &dummyHead;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }

        return dummyHead.next;
    }
};