"""
* 面试题34. 二叉树中和为某一值的路径（回溯法，清晰图解） - 二叉树中和为某一值的路径 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/mian-shi-ti-34-er-cha-shu-zhong-he-wei-mou-yi-zh-5/
"""


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res, path = [], []
        def recur(root, target):
            if root==None:
                return
            path.append(root.val)
            target -= root.val
            if target==0 and root.left==None and root.right==None:
                res.append(list(path))
            recur(root.left, target)
            recur(root.right, target)
            path.pop()
        recur(root, sum)
        return res