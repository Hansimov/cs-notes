"""
* 面试题63. 股票的最大利润（动态规划，清晰图解） - 股票的最大利润 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/solution/mian-shi-ti-63-gu-piao-de-zui-da-li-run-dong-tai-2/
"""

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float("inf")
        res = 0
        for price in prices:
            min_price = min(min_price, price)
            res = max(res, price-min_price)
        return res