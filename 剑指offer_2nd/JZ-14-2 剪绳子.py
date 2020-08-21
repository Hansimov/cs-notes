"""
* 面试题14- II. 剪绳子 II（数学推导 / 贪心思想 + 快速幂求余，清晰图解） - 剪绳子 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/
"""

class Solution:
    def mod_pow(self,x,n,p):
        rem = 1
        x = x % p
        while n>0:
            if n&1:
                rem = (rem*x)%p
            n>>=1
            if n>0:
                x = (x*x)%p
        return rem

    def cuttingRope(self, n: int) -> int:
        if n<=3:
            return n-1

        p = 1000000007
        a, b = n//3, n%3
        res = 0
        if b==0:
            res = self.mod_pow(3,a,p)
        elif b==1:
            res = (self.mod_pow(3,a-1,p)*4) % p
        else:
            res = (self.mod_pow(3,a,p)*2) % p

        return res
