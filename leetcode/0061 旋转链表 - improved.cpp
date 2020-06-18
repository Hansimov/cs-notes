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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL) return NULL;
        if (k==0) return head;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* left = dummyHead;
        ListNode* right = dummyHead;

        int n=0;
        for (int i=0; i<k; ++i) {
            if (right->next==NULL)
                break;
            right = right->next;
            ++n;
        }

        while (right->next) {
            right = right->next;
            left = left->next;
            ++n;
        }

        if (k>=n) {
            k = k % n;
            if (k==0)
                return head;
            // left = dummyHead;
            for (int i=0; i<n-k; ++i)
                left = left->next;
        }

        right->next = dummyHead->next;
        dummyHead->next = left->next;
        left->next = NULL;

        return dummyHead->next;

    }
};