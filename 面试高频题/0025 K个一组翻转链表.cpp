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
        ListNode *dum = new ListNode(0);
        dum->next = head;
        ListNode *start, *end=dum;  // first and last of k-group
        ListNode *pre=dum, *next;   // pre of start, next of end
        while (end->next) {
            for (int i=0; i<k && end; ++i)
                end = end->next;
            // not reach k nodes
            if (!end) break;
            // break current k-group from whole linked list
            start = pre->next;
            next = end->next;
            end->next = nullptr;
            // reverse k-group and connect to 
            pre->next = reverseLinkedList(start);
            start->next = next;
            // connect current (reversed) k-group with pre and next
            pre = start;
            end = start;
        }
        return dum->next;
    }
};