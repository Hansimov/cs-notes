class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        start = -1
        res = 0
        for i in range(len(s)):
            c = s[i]
            if c in mp:
                start = max(start, mp[c])
            res = max(res, i-start)
            mp[c] = i
        return res