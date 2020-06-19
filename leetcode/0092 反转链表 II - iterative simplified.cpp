/**

* 力扣刷题总结之链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/circle/article/YGr54o/

* 反转链表 II - 反转链表 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/fan-zhuan-lian-biao-ii-by-leetcode/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head==NULL) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *pre = dummyHead;
        for (int i=1; i<m; ++i)
            pre = pre->next;
        ListNode *start = pre->next;
        ListNode *nxt;
        for (int i=m; i<n; ++i) {
            nxt = start->next;
            start->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }

        return dummyHead->next;
    }
};