"""
* 面试题59 - I. 滑动窗口的最大值（单调队列，清晰图解） - 滑动窗口的最大值 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-i-hua-dong-chuang-kou-de-zui-da-1-6/
"""

import collections
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k==0:
            return []
        q = collections.deque()
        res = []
        for i in range(k):
            while q and q[-1] < nums[i]:
                q.pop()
            q.append(nums[i])
        res.append(q[0])
        for i in range(k, len(nums)):
            if q[0] == nums[i-k]:
                q.popleft()
            while q and q[-1] < nums[i]:
                q.pop()
            q.append(nums[i])
            res.append(q[0])
        return res
