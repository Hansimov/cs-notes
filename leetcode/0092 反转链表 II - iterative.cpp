/**

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
        ListNode *revListPre = pre;
        ListNode *cur = pre->next;
        ListNode *revListStart = cur;

        ListNode* tmp;
        pre = NULL;
        for (int i=m; i<=n; ++i) {
             tmp = cur->next;
             cur->next = pre;
             pre = cur;
             cur = tmp;
        }
        revListPre->next = pre;
        revListStart->next = cur;

        return dummyHead->next;
    }
};