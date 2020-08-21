"""
* 50. Pow(x, n) （快速幂，清晰图解） - Pow(x, n) - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/powx-n/solution/50-powx-n-kuai-su-mi-qing-xi-tu-jie-by-jyd/
"""

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x==0.0:
            return 0.0
        if n<0:
            x,n = 1/x, -n

        res = 1
        while n:
            if n&1:
                res *= x
            n >>=1
            if n:
                x *= x
        return res
