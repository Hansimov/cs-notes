"""
* 面试题47. 礼物的最大价值（动态规划，清晰图解） - 礼物的最大价值 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/solution/mian-shi-ti-47-li-wu-de-zui-da-jie-zhi-dong-tai-gu/
"""

class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: return 0
        m = len(grid)
        n = len(grid[0])
        for j in range(1,n):
            grid[0][j] += grid[0][j-1]
        for i in range(1,m):
            grid[i][0] += grid[i-1][0]
        for i in range(1,m):
            for j in range(1,n):
                grid[i][j] += max(grid[i][j-1], grid[i-1][j])
        return grid[-1][-1]