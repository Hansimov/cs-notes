"""
* 最小的k个数 - 最小的k个数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/zui-xiao-de-kge-shu-by-leetcode-solution/
* 从一场微软面试中领悟到的一些东西（x - 最小的k个数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/wei-ruan-mian-shi-jiao-xun-x-by-jerry_nju/
"""

from typing import List
import random

class Solution1:
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

import heapq
class Solution:
    # 用堆适合流式处理，比如数字个数非常多，内存一次性塞不下的场景
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0 or not arr: return []
        hp = [-x for x in arr[:k]] # python 的堆默认是最小堆，而题中要求是（保留）最小k个数，故需将原数取负以建立最大堆，不断逐出最大值，最后留下的k个数就是最小的
        heapq.heapify(hp)
        for i in range(k, len(arr)):
            if arr[i] < -hp[0]: # 若当前数字比入堆数字最大值小，则弹出堆的最大值，并将该数放入堆中
                heapq.heappop(hp)
                heapq.heappush(hp, -arr[i])
        res = [-x for x in hp]

        return res

# s = Solution()
# # nums = list(range(10))
# # random.shuffle(nums)
# nums = [0,0,2,3,2,1,1,2,0,4]
# print(nums)
# k = 3
# print(s.getLeastNumbers(nums, k))
