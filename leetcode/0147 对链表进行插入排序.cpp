/**

* 利用前一个插入位置提速 - 对链表进行插入排序 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/insertion-sort-list/solution/li-yong-qian-yi-ge-cha-ru-wei-zhi-ti-su-by-gui-lin/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode* dummyHead = new ListNode(INT_MIN);
        ListNode* pre = dummyHead;
        ListNode* cur;
        ListNode* tmp = head;
        while (tmp) {
            cur = tmp;
            tmp = tmp->next;
            if (pre->val > cur->val)
                pre = dummyHead;
            while (pre->next && cur->val > pre->next->val)
                pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
        }
        return dummyHead->next;
    }
};