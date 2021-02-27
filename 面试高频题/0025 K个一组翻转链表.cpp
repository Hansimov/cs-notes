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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* left=nullptr, *mid=head, *right;
        while (mid) {
            right = mid->next;
            mid->next = left;
            left = mid;
            mid = right;
        }
        return left;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dum = new ListNode(0);
        dum->next = head;
        ListNode* pre=dum, *next;
        ListNode* start,   *end=dum;
        while (end->next) {
            for (int i=0; i<k && end; ++i) {
                end = end->next;
            }
            if (!end) break;
            next = end->next;
            start = pre->next;
            end->next = nullptr;

            pre->next = reverseLinkedList(start);
            start->next = next;

            pre = start;
            end = start;
        }
        return dum->next;
    }
};