"""
* 面试题04. 二维数组中的查找（标志数，清晰图解） - 二维数组中的查找 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/
"""

class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        r,c = len(matrix)-1, 0
        while r >=0 and c <=len(matrix[0])-1:
            if target > matrix[r][c]:
                    c += 1
            elif target < matrix[r][c]:
                    r -= 1
            else:
                return True
        return False
