/**

* 画解算法：24. 两两交换链表中的节点 - 两两交换链表中的节点 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/hua-jie-suan-fa-24-liang-liang-jiao-huan-lian-biao/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        ListNode *pre, *nex;
        while (cur->next && cur->next->next) {
            pre = cur->next;
            nex = cur->next->next;
            cur->next = nex;
            pre->next = nex->next;
            nex->next = pre;
            cur = pre;
        }
        return dummyHead->next;
    }
};