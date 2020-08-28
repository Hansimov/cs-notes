"""
* 面试题50. 第一个只出现一次的字符（哈希表 / 有序哈希表，清晰图解） - 第一个只出现一次的字符 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/solution/mian-shi-ti-50-di-yi-ge-zhi-chu-xian-yi-ci-de-zi-3/
"""
import collections
class Solution:
    def firstUniqChar(self, s: str) -> str:
        hash_map = collections.OrderedDict()
        for c in s:
            hash_map[c] = not c in hash_map
        for k, v in hash_map.items():
            if v:
                return k
        return ' '
