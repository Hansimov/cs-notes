/**

* Merge K sorted linked lists | Set 1 - GeeksforGeeks 
    * https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

* Merge k sorted linked lists | Set 2 (Using Min Heap) - GeeksforGeeks 
    * https://www.geeksforgeeks.org/merge-k-sorted-linked-lists-set-2-using-min-heap/

* 4 种方法详解，🤷‍♀️必须秒懂！ - 合并K个排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/4-chong-fang-fa-xiang-jie-bi-xu-miao-dong-by-sweet/

* C++ 优先队列&两两合并&分治合并（图解） - 合并K个排序链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/c-you-xian-dui-lie-liang-liang-he-bing-fen-zhi-he-/
* Brief C++ solution with priority_queue - LeetCode Discuss 
    * https://leetcode.com/problems/merge-k-sorted-lists/discuss/10543/Brief-C%2B%2B-solution-with-priority_queue


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
private:
    struct compare {
        bool operator()(struct ListNode* a, struct ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto &ele: lists) {
            if (ele)
                pq.push(ele);
        }
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
            if (cur->next)
                pq.push(cur->next);

        }

        return dummyHead->next;
    }
};