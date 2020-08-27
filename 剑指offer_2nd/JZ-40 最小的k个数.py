"""
* 最小的k个数 - 最小的k个数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/zui-xiao-de-kge-shu-by-leetcode-solution/

"""

from typing import List
import random

class Solution:
    def partition(self, arr, b, e):
        pi = random.randint(b,e) # 随机选择保证 O(n) 复杂度
        pivot = arr[pi]
        arr[pi], arr[e] = arr[e], arr[pi]
        t = b
        for i in range(b,e):
            if arr[i] <= pivot:
                arr[i], arr[t] = arr[t], arr[i]
                t += 1
        arr[t], arr[e] = arr[e], arr[t] # 最后还要换回来
        return t

    def quick_select(self, arr, b, e, k):
        if b >= e: # 初始退出条件
            return
        k_tmp = self.partition(arr, b, e)
        if k_tmp == k:
            return
        elif k_tmp < k:
            self.quick_select(arr, k_tmp+1, e, k)
        else:
            self.quick_select(arr, b, k_tmp-1, k)

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0 or not arr: # 初始退出条件
            return []
        self.quick_select(arr, 0, len(arr)-1, k)
        return arr[:k]

# s = Solution()
# # nums = list(range(10))
# # random.shuffle(nums)
# nums = [0,0,2,3,2,1,1,2,0,4]
# print(nums)
# k = 3
# print(s.getLeastNumbers(nums, k))
