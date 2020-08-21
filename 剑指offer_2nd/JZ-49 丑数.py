"""
* 面试题49. 丑数（动态规划，清晰图解） - 丑数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/
* 丑数 II - 丑数 II - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode/

"""

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1]*n
        a,b,c = 0,0,0
        for i in range(1,n):
            n2, n3, n5 = dp[a]*2, dp[b]*3, dp[c]*5
            dp[i] = min(n2,n3,n5)
            if dp[i]==n2:
                a+=1
            if dp[i]==n3:
                b+=1
            if dp[i]==n5:
                c+=1
        return dp[n-1]