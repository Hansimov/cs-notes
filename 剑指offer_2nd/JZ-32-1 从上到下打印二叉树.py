"""
* 面试题32 - I. 从上到下打印二叉树（层序遍历 BFS ，清晰图解） - 从上到下打印二叉树 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/solution/mian-shi-ti-32-i-cong-shang-dao-xia-da-yin-er-ch-4/
* python3 deque（双向队列） - 扫驴 - 博客园 
    * https://www.cnblogs.com/saolv/p/9839711.html
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        res, q = [], deque()
        if not root:
            return []
        q.append(root)
        while q:
            head = q.popleft()
            res.append(head.val)
            if head.left:
                q.append(head.left)
            if (head.right):
                q.append(head.right)
        return res