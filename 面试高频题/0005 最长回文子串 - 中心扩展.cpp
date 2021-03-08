#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int L_res=0, R_res=0;
        for (int i=0; i<s.size(); ++i) {
            for (int j=0; j<=1; ++j) {
                int L = i;
                int R = i+j;
                while (L>=0 && R<s.size() && s[L]==s[R]) {
                    --L; ++R;
                }
                ++L; --R;
                if (R-L > R_res-L_res) {
                    L_res = L;
                    R_res = R;
                }
            }
        }
        return s.substr(L_res, R_res-L_res+1);
    }
};

int main() {
    Solution sol;
    string s = "cbbd";
    cout << sol.longestPalindrome(s) << endl;

    
    return 0;
}