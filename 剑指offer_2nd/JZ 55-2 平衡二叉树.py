"""
* 面试题55 - II. 平衡二叉树（从底至顶、从顶至底，清晰图解） - 平衡二叉树 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/solution/mian-shi-ti-55-ii-ping-heng-er-cha-shu-cong-di-zhi/
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# class Solution:
#     def get_depth(self, root:TreeNode) -> int:
#         if root == None:
#             return 0
#         return 1+max(self.get_depth(root.left), self.get_depth(root.right))
#     def isBalanced(self, root: TreeNode) -> bool:
#         if root==None:
#             return True
#         return self.isBalanced(root.left) and self.isBalanced(root.right) and abs(self.get_depth(root.left)-self.get_depth(root.right)) <= 1

class Solution:
    def get_depth(self, root) -> int:
        if root==None:
            return 0
        left = self.get_depth(root.left)
        if left == -1:
            return -1
        right = self.get_depth(root.right)
        if right == -1:
            return -1
        if abs(left-right)<=1:
            return max(left,right)+1
        else:
            return -1

    def isBalanced(self, root:TreeNode) -> bool:
        return not self.get_depth(root) == -1