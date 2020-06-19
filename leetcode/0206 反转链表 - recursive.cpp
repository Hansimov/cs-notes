/**

* 步步拆解：如何递归地反转链表的一部分 - 反转链表 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};