/**

* 回文链表（1.栈，2.快慢指针+翻转） - 回文链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-1zhan-2kuai-man-zhi-zhen-fan-zhu/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        ListNode* nxt;
        while (fast && fast->next) {
            fast = fast->next->next;
            nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }

        if (fast)
            slow = slow->next;

        while(slow && pre) {
            if (slow->val != pre->val)
                return false;
            slow = slow->next;
            pre = pre->next;
        }
        if (slow || pre)
            return false;
        return true;

    }
};