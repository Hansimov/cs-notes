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
    ListNode* reverseList(ListNode* t) {
        if (!t) return NULL;
        ListNode* pre = NULL;
        ListNode* cur = t;
        ListNode* nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        if (!head) return ;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverseList(slow->next);
        slow->next = NULL;
        ListNode* tmp, *tmp2;
        while (head || head2) {
            if (head) {
                tmp = head->next;
                head->next = head2;
                head = tmp;
            }
            if (head2) {
                tmp2 = head2->next;
                head2->next = head;
                head2 = tmp2;
            }
        }
    }
};