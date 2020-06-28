/**

* 148. 排序链表-bottom-to-up O(1) 空间 - 排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/

* Sort List （归并排序链表） - 排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/

* lioney:) C++归并排序链表 - 排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/sort-list/solution/lioney-cgui-bing-pai-xu-lian-biao-by-lioney/


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeList(ListNode* leftList, ListNode* rightList) {
        if (leftList==NULL) return rightList;
        if (rightList==NULL) return leftList;
        if (leftList->val < rightList->val) {
            leftList->next = mergeList(leftList->next, rightList);
            return leftList;
        } else {
            rightList->next = mergeList(leftList, rightList->next);
            return rightList;
        }
    }

    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre;

        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return mergeList(sortList(head), sortList(slow));
    }
};