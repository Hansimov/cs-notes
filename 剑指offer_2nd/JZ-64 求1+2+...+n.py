"""
* 面试题64. 求 1 + 2 + … + n（逻辑符短路，清晰图解） - 求1+2+…+n - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/qiu-12n-lcof/solution/mian-shi-ti-64-qiu-1-2-nluo-ji-fu-duan-lu-qing-xi-/
* 评论区
    * https://leetcode-cn.com/problems/qiu-12n-lcof/solution/mian-shi-ti-64-qiu-1-2-nluo-ji-fu-duan-lu-qing-xi-/423849
"""

class Solution:
    def sumNums(self, n: int) -> int:
        return n and (n + self.sumNums(n-1))