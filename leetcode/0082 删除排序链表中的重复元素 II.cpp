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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        ListNode* tmp;
        while (cur) {
            if (cur->next && cur->next->val == cur->val) {
                while(cur->next && cur->next->val == cur->val) {
                    tmp = cur->next;
                    // delete tmp;
                    cur->next = cur->next->next;
                }
                // delete cur;
                cur = cur->next;
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        return dummyHead->next;
    }
};