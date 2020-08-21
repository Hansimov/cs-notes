"""
* 快速排序 - 维基百科，自由的百科全书 
    * https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F

* algorithm - Quicksort with Python - Stack Overflow 
    https://stackoverflow.com/a/47947167
* Python Program for QuickSort - GeeksforGeeks 
    * https://www.geeksforgeeks.org/python-program-for-quicksort/

* 算法 3：最常用的排序——快速排序 - 坐在马桶上学算法 - 极客学院Wiki 
    * https://wiki.jikexueyuan.com/project/easy-learn-algorithm/fast-sort.html
* algorithm - Quicksort with Python - Stack Overflow 
    * https://stackoverflow.com/questions/18262306/quicksort-with-python
* C++ Program for QuickSort - GeeksforGeeks 
    * https://www.geeksforgeeks.org/cpp-program-for-quicksort/
* 一篇文章让你真正了解快速排序 - 汤姆C - SegmentFault 思否 
    * https://segmentfault.com/a/1190000017314698
* Quick sort in 4 minutes - YouTube 
    * https://www.youtube.com/watch?v=Hoixgm4-P4M

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

import random


def quicksort(nums: List, b: int, e: int, random_anchor=False):
    if e - b <= 1: return
    p1 = b + 1

    if random_anchor:
        # optionally, randomly select a number as anchor
        k = random.randint(b, e-1)
        nums[b], nums[k] = nums[k], nums[b]

    anchor = nums[b]
    for i in range(b + 1, e):
        if nums[i] <= nums[b]:
            # swap nums[p1] and nums[i]
            nums[p1], nums[i] = nums[i], nums[p1]
            p1 += 1
    nums[p1 - 1], nums[b] = nums[b], nums[p1 - 1]
    quicksort(nums, b, p1, random_anchor)
    quicksort(nums, p1, e, random_anchor)


if __name__ == "__main__":
    # from comparator import Comparator
    import random

    nums = list(range(20))
    random.shuffle(nums)
    print(nums)
    quicksort(nums, 0, len(nums), random_anchor=True)
    print(nums)