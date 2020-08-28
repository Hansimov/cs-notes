"""
* 哈希，两次遍历 - 复杂链表的复制 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/ha-xi-liang-ci-bian-li-by-gao-xian-feng/
* 复杂链表的复制-（看了绝对秒懂的思路）简单易懂的三步解决问题 - 复杂链表的复制 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/fu-za-lian-biao-de-fu-zhi-jian-dan-yi-dong-de-san-/
* 图解 链表的深拷贝 - 复杂链表的复制 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/lian-biao-de-shen-kao-bei-by-z1m/
* 面试题35. 复杂链表的复制 三种常见解法 - 复杂链表的复制 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/mian-shi-ti-35-fu-za-lian-biao-de-fu-zhi-san-chong/
* 通过HashMap来实现 - 复杂链表的复制 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/tong-guo-hashmaplai-shi-xian-by-try-62/
"""

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

import copy
class Solution1:
    def copyRandomList(self, head: 'Node') -> 'Node':
        return copy.deepcopy(head)

class Solution2:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        p = head
        hash_map = {None: None}
        while p:
            hash_map[p] = Node(p.val)
            p = p.next

        p = head
        while p:
            hash_map[p].next = hash_map[p.next]
            hash_map[p].random = hash_map[p.random]
            p = p.next
        return hash_map[head]

class Solution:
    def copyRandomList(self, head: 'None') -> 'None':
        if not head: return None

        # clone nodes
        p = head
        while p:
            p_copy = Node(p.val)
            p_copy.next = p.next
            p.next = p_copy
            p = p_copy.next

        # copy random pointers
        p = head
        while p:
            p.next.random = p.random.next if p.random else None
            p = p.next.next

        # split two linked list
        p = head
        p_copy = head.next
        head_copy = head.next
        while p:
            p.next = p.next.next
            p_copy.next = p_copy.next.next if p_copy.next else None
            p = p.next
            p_copy = p_copy.next
        return head_copy

