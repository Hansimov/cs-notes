/**

* 合并K个排序链表 - 合并K个排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/


* 4 种方法详解，🤷‍♀️必须秒懂！ - 合并K个排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/4-chong-fang-fa-xiang-jie-bi-xu-miao-dong-by-sweet/

* C++ 优先队列&两两合并&分治合并（图解） - 合并K个排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/c-you-xian-dui-lie-liang-liang-he-bing-fen-zhi-he-/


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
    ListNode* mergeTwoLists(ListNode*a, ListNode*b) {
        if (!a) return b;
        if (!b) return a;

        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        ListNode *ap = a, *bp = b;

        while (ap && bp) {
            if (ap->val > bp->val) {
                cur->next = bp;
                bp = bp->next;
            } else {
                cur->next = ap;
                ap = ap->next;
            }
            cur = cur->next;
        }

        cur->next = ap ? ap : bp;

        return dummyHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int sz = lists.size();
        for (int step=1; step<sz; step*=2) {
            for (int i=step; i<sz; i+=2*step) {
                lists[i-step] = mergeTwoLists(lists[i-step], lists[i]);
                lists[i] = NULL;
            }
        }
        return lists[0];
    }
};