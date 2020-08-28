"""
* 6行代码一次遍历 - 反转链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/6xing-dai-ma-yi-ci-bian-li-by-chitoseyono/
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        left = None
        mid = head
        while mid:
            right = mid.next
            mid.next = left
            left = mid
            mid = right
        return left