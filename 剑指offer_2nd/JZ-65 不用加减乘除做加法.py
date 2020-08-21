"""
* 面试题65. 不用加减乘除做加法（位运算，清晰图解） - 不用加减乘除做加法 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/
* 禁止套娃，如何用位运算完成加法？ - 不用加减乘除做加法 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/jin-zhi-tao-wa-ru-he-yong-wei-yun-suan-wan-cheng-j/
"""

class Solution:
    def add(self, a: int, b: int) -> int:
        m = 0xffffffff
        a, b = a&m, b&m
        while b!=0:
            a, b = a^b, (a&b)<<1 & m
        
        if a<=0x7fffffff:
            return a
        else:
            return ~(a^m)