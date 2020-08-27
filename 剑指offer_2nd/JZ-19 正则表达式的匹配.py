"""
* 逐行详细讲解，由浅入深，dp和递归两种思路 - 正则表达式匹配 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zhu-xing-xiang-xi-jiang-jie-you-qian-ru-shen-by-je/
* 动态规划超详细解答，由繁入简。 - 正则表达式匹配 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/dong-tai-gui-hua-chao-xiang-xi-jie-da-you-fan-ru-j/
* 动态规划，二维数组，击败双100% - 正则表达式匹配 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/dong-tai-gui-hua-er-wei-shu-zu-by-loick/
"""

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        dp = [[False]*(n+1) for _ in range(m+1)] # dp[i][j]: is s[:i) matches p[:j)

        dp[0][0] = True
        for i in range(m+1):
            for j in range(1,n+1):
                if i==0:
                    dp[i][j] = (j>=2) and (p[j-1]=='*') and (dp[i][j-2])
                elif p[j-1] in [s[i-1], '.']:
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1]=='*':
                    dp[i][j] = j>=2 and dp[i][j-2] or ((p[j-2] in [s[i-1],'.']) and dp[i-1][j])
                else:
                    dp[i][j] = False

        return dp[-1][-1]
