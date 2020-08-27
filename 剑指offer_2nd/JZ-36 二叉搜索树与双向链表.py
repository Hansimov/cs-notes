"""
* 面试题36. 二叉搜索树与双向链表（中序遍历，清晰图解） - 二叉搜索树与双向链表 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/mian-shi-ti-36-er-cha-sou-suo-shu-yu-shuang-xian-5/
"""
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def dfs(cur):
            if not cur: return
            dfs(cur.left)
            if self.pre:
                self.pre.right = cur
                cur.left = self.pre
            else:
                self.head = cur
            self.pre = cur
            dfs(cur.right)
        if not root: return None
        self.pre = None
        dfs(root)
        self.head.left = self.pre
        self.pre.right = self.head
        return self.head

