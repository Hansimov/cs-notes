class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int n = s.size();
        if (n==0) return 0;
        int res=0;
        int L=0, R=0;
        while (R<n) {
            while (R<n && !us.count(s[R]))
                us.insert(s[R++]);
            res = max(res, R-L);
            us.erase(s[L++]);
        }
        return res;
    }
};