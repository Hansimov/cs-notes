"""
* 由浅入深，快速幂算法详解 - 超级次方 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/super-pow/solution/you-qian-ru-shen-kuai-su-mi-suan-fa-xiang-jie-by-l/
* 快速幂取模算法 - 王陸 - 博客园 
    * https://www.cnblogs.com/wkfvawl/p/9125224.html
* 50. Pow(x, n) （快速幂，清晰图解） - Pow(x, n) - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/powx-n/solution/50-powx-n-kuai-su-mi-qing-xi-tu-jie-by-jyd/
"""

# class Solution:
#     def mod_pow(self,a,n,p) -> int:
#         if n==0:
#             return 1
#         a %= p
#         res = 1
#         for _ in range(n):
#             res = (res * a) %p
#         return res

#     def superPow(self, a: int, b: List[int]) -> int:
#         p = 1337
#         a %= p
#         res = 1
#         for n in b:
#             res = (self.mod_pow(a,n,p) * self.mod_pow(res,10,p)) % p
#         return res

class Solution:
    def mod_pow(self, a, n, p) -> int:
        if n==0:
            return 1
        a %= p
        res = 1
        while n>0:
            if n&1:
                res = (res*a) % p
            n >>= 1
            if n<=0: break
            a = (a*a) % p
        return res

    def superPow(self, a:int, b: List[int]) -> int:
        p = 1337
        a %= p
        res = 1
        for n in b:
            res = (self.mod_pow(a,n,p) * self.mod_pow(res,10,p)) % p
        return res
