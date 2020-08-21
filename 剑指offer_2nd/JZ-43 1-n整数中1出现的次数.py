"""
* 面试题43. 1～n 整数中 1 出现的次数（清晰图解） - 1～n整数中1出现的次数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
"""

class Solution:
    def countDigitOne(self, n: int) -> int:
        high = n // 10
        low = 0
        cur = n % 10
        digit = 1
        res = 0
        while cur != 0 or high != 0:
            if cur == 0:
                res += high * digit
            elif cur == 1:
                res += high * digit + low + 1
            else:
                res += high * digit + digit
            low = low + cur * digit
            cur = high % 10
            high = high // 10
            digit = digit * 10
        return res