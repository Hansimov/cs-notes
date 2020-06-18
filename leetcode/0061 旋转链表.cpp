/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            ++len;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int n = getLength(head);
        if (k>=n) k = k % n;
        if (k==0) return head;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* left = dummyHead;
        ListNode* right = dummyHead;

        for (int i=0; i<k; ++i) {
            right = right->next;
        }

        while (right->next) {
            left = left->next;
            right = right->next;
        }
        right->next = dummyHead->next;
        dummyHead->next = left->next;
        left->next = NULL;

        return dummyHead->next;

    }
};