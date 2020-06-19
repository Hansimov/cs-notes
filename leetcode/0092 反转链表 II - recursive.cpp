/**

* 反转链表 II - 反转链表 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/fan-zhuan-lian-biao-ii-by-leetcode/

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
    ListNode* revListNext=NULL;
    ListNode* reverseFirstNNodes(ListNode* head, int n) {
        if (n==1) {
            revListNext = head->next;
            return head;
        }
        ListNode* last = reverseFirstNNodes(head->next, n-1);

        head->next->next = head;
        head->next = revListNext;

        return last;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head==NULL) return head;
        if (m==1)
            return reverseFirstNNodes(head, n);
        head->next = reverseBetween(head->next, m-1, n-1);

        return head;
    }
};