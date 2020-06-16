/**

* 删除链表的倒数第N个节点 - 删除链表的倒数第N个节点 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-by-l/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *left = preHead;
        ListNode *right = preHead;
        for (int i=0; i<n+1; ++i) {
            right = right->next;
        }
        while (right) {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return preHead->next;
    }
};