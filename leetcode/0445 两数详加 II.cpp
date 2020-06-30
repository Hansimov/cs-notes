/**

* 两数相加 II - 两数相加 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/add-two-numbers-ii/solution/liang-shu-xiang-jia-ii-by-leetcode-solution/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;

        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = NULL;
        int sum = 0, carry = 0;
        while (!s1.empty() || !s2.empty() || carry!=0) {
            int val1 = s1.empty() ? 0 : s1.top();
            if (!s1.empty()) s1.pop();
            int val2 = s2.empty() ? 0 : s2.top();
            if (!s2.empty()) s2.pop();
            sum = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;

            ListNode *cur = new ListNode(sum);
            cur->next = head;
            head = cur;
        }

        return head;
    }
};