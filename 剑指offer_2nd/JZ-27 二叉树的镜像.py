"""
* 面试题27. 二叉树的镜像（递归 / 辅助栈，清晰图解） - 二叉树的镜像 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/solution/mian-shi-ti-27-er-cha-shu-de-jing-xiang-di-gui-fu-/
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root==None:
            return root
        root.left, root.right = self.mirrorTree(root.right), self.mirrorTree(root.left)
        return root
