"""
* 面试题29. 顺时针打印矩阵（模拟、设定边界，清晰图解） - 顺时针打印矩阵 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/mian-shi-ti-29-shun-shi-zhen-da-yin-ju-zhen-she-di/

* 删除第一行+逆时针旋转 Python5行代码 - 顺时针打印矩阵 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/shan-chu-di-yi-xing-ni-shi-zhen-xuan-zhuan-python5/

"""

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []
        l = 0
        r = len(matrix[0])-1
        t = 0
        b = len(matrix)-1
        res = []
        while True:
            for j in range(l, r+1):
                res.append(matrix[t][j])
            t+=1
            if t>b: break
            for i in range(t, b+1):
                res.append(matrix[i][r])
            r-=1
            if l>r: break
            for j in range(r, l-1, -1):
                res.append(matrix[b][j])
            b-=1
            if t>b: break
            for i in range(b ,t-1, -1):
                res.append(matrix[i][l])
            l+=1
            if l>r: break
        return res