"""
* 面试题17. 打印从 1 到最大的 n 位数（分治算法 / 全排列，清晰图解） - 打印从1到最大的n位数 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/mian-shi-ti-17-da-yin-cong-1-dao-zui-da-de-n-wei-2/
"""

# class Solution:
#     def printNumbers(self, n: int) -> List[int]:
#         return list(range(1,10**n))

class Solution:
    def printNumbers(self, n: int) -> List[int]:
        def dfs(x):
            if x==n:
                if self.is_zero:
                    self.is_zero = False
                else:
                    tmp = ''.join(num).lstrip('0')
                    res.append(int(tmp))
                return
            for i in range(10):
                num[x] = str(i)
                dfs(x+1)

        self.is_zero = True
        res = []
        num = ['0'] * n
        dfs(0)
        return res