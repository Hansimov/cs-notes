"""
* 面试题07. 重建二叉树（递归法，清晰图解） - 重建二叉树 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-di-gui-fa-qin/
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.map = {}
        self.pre = preorder
        for i in range(len(inorder)):
            self.map[inorder[i]] = i
        return self.recur(0, 0, len(inorder)-1)

    def recur(self, pre_root_idx, in_left, in_right) -> TreeNode:
        if in_left > in_right:
            return
        root = TreeNode(self.pre[pre_root_idx])
        in_root_idx = self.map[root.val]
        root.left = self.recur(pre_root_idx+1, in_left, in_root_idx-1)
        root.right = self.recur(pre_root_idx+in_root_idx-in_left+1, in_root_idx+1, in_right)
        return root