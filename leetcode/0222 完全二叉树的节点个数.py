# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# class Solution:
#     def countNodes(self, root: TreeNode) -> int:
#         if root:
#             return 1 + self.countNodes(root.left) + self.countNodes(root.right)
#         else:
#             return 0

"""
* 完全二叉树的节点个数 - 完全二叉树的节点个数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/wan-quan-er-cha-shu-de-jie-dian-ge-shu-by-leetcode/
"""

class Solution:
    def calc_depth(self, node: TreeNode) -> int:
        d = 0
        while node.left:
            node = node.left
            d += 1
        return d

    def is_leaf_exist(self, idx: int, d:int, node: TreeNode) -> bool:
        left, right = 0, 2**d-1
        for _ in range(d):
            mid = left + (right-left) // 2
            if idx <= mid:
                node = node.left
                right = mid
            else:
                node = node.right
                left = mid + 1
        return not node==None

    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        d = self.calc_depth(root)
        if d==0:
            return 1
        left, right = 0, 2**d-1
        while left <= right:
            mid = left + (right-left)//2
            if self.is_leaf_exist(mid, d, root):
                left = mid+1
            else:
                right = mid-1
        return left + 2**d-1