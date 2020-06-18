/**

* 分隔链表 - 分隔链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/partition-list/solution/fen-ge-lian-biao-by-leetcode/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head==NULL) return NULL;
        ListNode* dmSmall = new ListNode(0);
        ListNode* pSmall = dmSmall;
        ListNode* dmLarge = new ListNode(0);
        ListNode* pLarge = dmLarge;
        ListNode* cur = head;
        while (cur) {
            if (cur->val<x) {
                pSmall->next = cur;
                pSmall = pSmall->next;
            } else {
                pLarge->next = cur;
                pLarge = pLarge->next;
            }
            cur = cur->next;
        }
        pLarge->next = NULL;
        pSmall->next = dmLarge->next;
        return dmSmall->next;
    }
};