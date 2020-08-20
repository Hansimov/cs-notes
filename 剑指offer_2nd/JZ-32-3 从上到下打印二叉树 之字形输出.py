"""
* 面试题32 - III. 从上到下打印二叉树 III（层序遍历 BFS / 双端队列，清晰图解） - 从上到下打印二叉树 III - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/solution/mian-shi-ti-32-iii-cong-shang-dao-xia-da-yin-er--3/
"""

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
            if len(res) % 2 == 1:
                tmp.reverse()
            res.append(tmp)
        return res
