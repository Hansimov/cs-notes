"""
* 面试题16. 数值的整数次方（快速幂，清晰图解） - 数值的整数次方 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/mian-shi-ti-16-shu-zhi-de-zheng-shu-ci-fang-kuai-s/
"""
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        res = 1
        if n<0:
            x = 1/x
            n = -n
        while n:
            if n&1:
                res *= x
            x *= x
            n >>= 1
        return res