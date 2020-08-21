"""
* 面试题67. 把字符串转换成整数（数字越界处理，清晰图解） - 把字符串转换成整数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/solution/mian-shi-ti-67-ba-zi-fu-chuan-zhuan-huan-cheng-z-4/
"""

class Solution:
    def strToInt(self, s: str) -> int:
        res = 0
        i = 0
        sign = 1
        int_min = -2**31
        int_max = 2**31-1
        bound = 2**31//10
        if not s:
            return 0
        while s[i] == ' ':
            i += 1
            if i==len(s):
                return 0
        if s[i] =='-':
            sign = -1
        if s[i] in "+-":
            i += 1
        for c in s[i:]:
            if not '0' <= c <= '9':
                break
            if res > bound or res==bound and c>'7': # 无论如果等于8，则恰好是 int_max
                return int_max if sign == 1 else int_min
            res = res*10 + ord(c) - ord('0')

        return sign * res
