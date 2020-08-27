"""
* 面试题42. 连续子数组的最大和（动态规划，清晰图解） - 连续子数组的最大和 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/solution/mian-shi-ti-42-lian-xu-zi-shu-zu-de-zui-da-he-do-2/
"""

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dp[i]: max sum of all aubarrays ends with nums[i]
        # modify nums to reduce space
        for i in range(1,len(nums)):
            nums[i] += max(nums[i-1], 0)
        return max(nums)