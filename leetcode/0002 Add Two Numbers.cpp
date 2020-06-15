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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        
        int sum=0, carry=0;
        ListNode preHead= ListNode(0);
        ListNode *cur = &preHead;

        ListNode *t1 = l1;
        ListNode *t2 = l2;
        while (t1 || t2) {
            sum = (t1 ? t1->val : 0) + (t2? t2->val : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        if (carry)
            cur->next = new ListNode(carry);

        return preHead.next;
    }
};