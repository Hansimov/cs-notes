"""
* 面试题18. 删除链表的节点（双指针，清晰图解） - 删除链表的节点 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/mian-shi-ti-18-shan-chu-lian-biao-de-jie-dian-sh-2/
* 详解 时间复杂度从 O(N) 到 O(1) - 删除链表的节点 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/cong-on-dao-o1-by-ml-zimingmeng/
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        dum = ListNode(0)
        dum.next = head
        cur = dum
        while cur.next:
            if cur.next.val == val:
                cur.next = cur.next.next
                break
            else:
                cur = cur.next
        return dum.next

