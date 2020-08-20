"""
* 有了这套模板，女朋友再也不用担心我刷不动 LeetCode 了 - 知乎 
    * https://zhuanlan.zhihu.com/p/86136802
* Leetcode 常用算法 Python 模板 - 知乎 
    * https://zhuanlan.zhihu.com/p/98065331

"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return f"{self.val}->{str(self.next)}"

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def __str__(self):
        # Pre-order traversal
        res, _ = encode_tree_visual(self)

        return '\n'.join(res)
        # if self.left or self.right:
        #     res = ','.join(map(str, [self.val, self.left, self.right]))
        #     res = f"[{res}]"
        # else:
        #     res = str(self.val)
        # return res


    def pre_order(self):
        return str(self)

    def in_order(self):
        if not isinstance(self, TreeNode): return str(self)
        if self.left or self.right:
            res = ','.join(
                map(TreeNode.in_order, [self.left, self.val, self.right]))
            res = f"[{res}]"
        else:
            res = str(self.val)
        return res


def generate_sll_from_list(values):
    D = c = ListNode(0)

    for v in values:
        c.next = ListNode(v)
        c = c.next

    res, D.next = D.next, None
    return res


def parse_tree_str(tree_str):
    import re
    tree_str = re.sub('[\[\] ]', '', tree_str)
    return [int(s) if s.isdigit() else None for s in tree_str.split(',')]


def generate_tree(input_data):
    # io and edge conditions
    if isinstance(input_data, str): input_data = parse_tree_str(input_data)
    if not input_data: return None

    idx = 1
    queue = [TreeNode(input_data[0])]
    root = queue[0]
    while idx < len(input_data):
        cur = queue.pop(0)
        if input_data[idx] is not None:
            cur.left = TreeNode(input_data[idx])
            queue.append(cur.left)
        idx += 1

        if idx == len(input_data): break
        if input_data[idx] is not None:
            cur.right = TreeNode(input_data[idx])
            queue.append(cur.right)
        idx += 1

    return root


def print_sll(head):
    print(head)



from functools import partial


def encode_tree_visual(root):
    if not root: return ['N'], 1
    if not (root.left or root.right): return [str(root.val)], len(str(root.val))
    left, left_width = encode_tree_visual(root.left)
    right, right_width = encode_tree_visual(root.right)

    mxheight = max(len(left), len(right))
    left, right = pad_tree_visual(left, mxheight), pad_tree_visual(right, mxheight)
    root_str = str(root.val)
    root_width = len(root_str)
    tree_visual = [' ' * left_width + root_str + ' ' * right_width]
    for i in range(mxheight):
        line = left[i] + ' ' * root_width + right[i]
        tree_visual.append(line)

    return tree_visual, left_width + root_width + right_width

def pad_tree_visual(tree, height):
    tree_len = len(tree[0]) if tree else 0
    while len(tree) < height:
        tree.append(' ' * tree_len)
    return tree

def encode_tree(root, mode='pre_order'):
    if not isinstance(root, TreeNode): return str(root)
    if not (root.left or root.right):
        return str(root)
    else:
        if mode == 'pre_order':
            return ','.join(map(partial(encode_tree, mode=mode), [root.val, root.left, root.right]))

def print_tree(root, mode='visual'):
    if mode == 'pre_order':
        print(encode_tree(root, mode))
    elif mode == 'visual':
        tree_vis, _ = encode_tree_visual(root)
        for l in tree_vis:
            print(l)

"""
"""

#!/usr/bin/env python
try:
    import colored_traceback.auto
    import utils
    from utils import ListNode, TreeNode
    from utils import generate_tree, print_tree
    DEBUG = True
except ImportError:
    DEBUG = False


def debugprint(*stuff):
    if DEBUG: print(*stuff)


import sys
from collections import defaultdict, Counter
from itertools import product, combinations, count
from functools import reduce, cmp_to_key, partial, lru_cache
from bisect import bisect, insort, bisect_left, bisect_right
from heapq import heapify, heappop, heappush, nsmallest, nlargest
from typing import List
from operator import mul, add, xor

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        p0, p1 = 0, -sys.maxsize
        for p in prices:
            p0, p1 = max(p0, p1 + p), max(-p, p1)
        return p0

if DEBUG:
    from comparator import Comparator
    print(Solution().maxProfit([7,6,4,3,1]))
