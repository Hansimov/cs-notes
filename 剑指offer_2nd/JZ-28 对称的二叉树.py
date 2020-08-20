# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def recur(left, right) -> bool:
            if left==None and right==None:
                return True
            if left==None or right==None or left.val != right.val:
                return False
            return recur(left.left, right.right) and recur(left.right, right.left)

        if root==None:
            return True
        else:
            return recur(root.left, root.right)