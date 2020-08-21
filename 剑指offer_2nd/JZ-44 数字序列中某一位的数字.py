"""
* 面试题44. 数字序列中某一位的数字（迭代 + 求整 / 求余，清晰图解） - 数字序列中某一位的数字 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/mian-shi-ti-44-shu-zi-xu-lie-zhong-mou-yi-wei-de-6/
"""

class Solution:
    def findNthDigit(self, n: int) -> int:
        # 注意“第i位”中，i从0开始，因此（为了方便计算）很多细节要稍作调整，比如 count 和 start 的初始值
        digit = 1 # digit位数  1, 2, 3, 4 ...
        start = 1 # digit位数的开始数字  1(0), 10, 100, 1000 ...
        count = 9 # digit位数的数位数量  9(10), 90*2, 900*3, 9000*4 ...

        while n>count:
            n -= count
            digit += 1
            start *= 10
            count = 9 * start * digit
        num = start + (n-1)//digit
        res = int(str(num)[(n-1)%digit])
        return res