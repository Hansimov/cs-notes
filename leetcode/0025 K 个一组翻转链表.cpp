/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedlist(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* next;
        ListNode* start;
        ListNode* end = dummyHead;
        while (end->next) {
            for (int i=0; i<k && end; ++i) {
                end = end->next;
            }
            if (end==NULL) break;
            next = end->next;
            start = pre->next;
            end->next = NULL;

            pre->next = reverseLinkedlist(start);
            start->next = next;

            pre = start;
            end = start;
        }
        return dummyHead->next;
    }
};