"""
* 面试题15. 二进制中 1 的个数（位运算，清晰图解） - 二进制中1的个数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/solution/mian-shi-ti-15-er-jin-zhi-zhong-1de-ge-shu-wei-yun/
"""

# class Solution:
#     def hammingWeight(self, n: int) -> int:
#         res = 0
#         while n:
#             res += n&1
#             n >>= 1
#         return res

class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            res += 1
            n &= n-1
        return res
