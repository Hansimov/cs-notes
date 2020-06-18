/**

* 旋转链表 - 旋转链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/rotate-list/solution/xuan-zhuan-lian-biao-by-leetcode/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0) return head;
        if (head==NULL) return NULL;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;

        int n=0;
        while (cur->next) {
            cur = cur->next;
            ++n;
        }

        if (k%n==0) return head;
        cur->next = dummyHead->next;

        cur = dummyHead;
        for (int i=0; i<n-k%n;++i) {
            cur = cur->next;
        }
        dummyHead->next = cur->next;
        cur->next = NULL;

        return dummyHead->next;
    }
};