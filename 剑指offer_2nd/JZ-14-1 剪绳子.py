"""
* 面试题14- I. 剪绳子（数学推导 / 贪心思想，清晰图解） - 剪绳子 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
"""

import math
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n<=3:
            return n-1
        a = n // 3
        b = n % 3
        res = 0
        if b==0:
            res = int(math.pow(3,a))
        elif b==1:
            res = int(math.pow(3,a-1)*4)
        else:
            res = int(math.pow(3,a)*2)

        return res