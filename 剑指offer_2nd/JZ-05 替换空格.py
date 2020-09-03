"""
* 面试题05. 替换空格 （极简，清晰图解） - 替换空格 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/solution/mian-shi-ti-05-ti-huan-kong-ge-ji-jian-qing-xi-tu-/
"""

class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(" ", "%20")