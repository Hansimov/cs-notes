"""
* 面试题48. 最长不含重复字符的子字符串（动态规划 / 双指针 + 哈希表，清晰图解） - 最长不含重复字符的子字符串 - 力扣（LeetCode） 
    * https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/mian-shi-ti-48-zui-chang-bu-han-zhong-fu-zi-fu-d-9/
"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {} # mp[s[i]]: last index of char s[i]
        res = 0
        left = -1
        for i in range(len(s)):
            if s[i] in mp:
                left = max(mp[s[i]], left)
            mp[s[i]] = i
            res = max(res, i-left)
        return res

