class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (auto &ch: s) {
            res = res*26 + (ch-'A'+1);
        }
        return res;
    }
};