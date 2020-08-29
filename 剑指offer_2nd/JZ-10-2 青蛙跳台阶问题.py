"""
* 面试题10- II. 青蛙跳台阶问题（动态规划，清晰图解） - 青蛙跳台阶问题 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/solution/mian-shi-ti-10-ii-qing-wa-tiao-tai-jie-wen-ti-dong/
"""
class Solution:
    def numWays(self, n: int) -> int:
        res = 1
        a = 1 # f(0): f(0) = f(2)-f(1) = 2-1 = 1
        b = 1 # f(1)
        for _ in range(n):
            sum = (a+b)% 1000000007
            a = b
            b = sum
        return a