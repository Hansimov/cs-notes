# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res, q = [], collections.deque()
        q.append(root)
        while q:
            tmp = []
            for _ in range(len(q)):
                head = q.popleft()
                tmp.append(head.val)
                if head.left:
                    q.append(head.left)
                if head.right:
                    q.append(head.right)
            res.append(tmp)
        return res
