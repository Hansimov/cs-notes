"""
* 面试题20. 表示数值的字符串（有限状态自动机，清晰图解） - 表示数值的字符串 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/mian-shi-ti-20-biao-shi-shu-zhi-de-zi-fu-chuan-y-2/
"""

class Solution:
    def isNumber(self, s: str) -> bool:
        states = [
            {' ':0, 's':1, 'd':2, '.':4},   # 0, start with ' '
            {'d':2, '.':4},                 # 1, sign before 'e'
            {'d':2, '.':3, 'e':5, ' ':8},   # 2, digit before '.'
            {'d':3, 'e':5, ' ':8},          # 3, '.' or digit after '.'
            {'d':3},                        # 4, digit after dot (when '.' before is ' ')
            {'s':6, 'd':7},                 # 5, 'e|E'
            {'d':7},                        # 6, sign after 'e'
            {'d':7, ' ':8},                 # 7, digit after 'e'
            {' ':8},                        # 8, end with blank
        ]
        p = 0               # start with state 0
        for c in s:
            if '0'<=c<='9': # digit
                t = 'd'
            elif c in "+-": # sign
                t = 's'
            elif c in "eE": # e or E
                t = 'e'
            elif c in '. ': # dot, blank
                t = c
            else:           # unknown
                t = "*"
            if t not in states[p]:
                return False
            p = states[p][t]
        return p in [2,3,7,8]