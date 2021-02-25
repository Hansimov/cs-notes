class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int num = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=1; ++j) {
                int L = i;
                int R = i+j;
                while (L>=0 && R<n && s[L--]==s[R++])
                    ++num;
            }
        }
        return num;
    }
};