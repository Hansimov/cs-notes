// Longest Palindromic Substring - GeeksforGeeks
//   https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// Manacher's algorithm: 最长回文子串算法
//   https://www.cnblogs.com/egust/p/4580299.html

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
string longestPalindrome(string s) {
    int maxlen=0, maxlen_last=0;
    int start, end, start_last;
    string subs;

    if (s.empty()) {
        subs = s;
        return subs;
    }
    // [0, s.size()-1]
    for (int i=0; i<=2*s.size()-2; ++i) {
        start = i/2;
        end = (i+1)/2;
        if ((s.size()-end)*2+(end-start)-1 <= maxlen_last){
            break;
        }
        while (start>=0 && end<=s.size()-1){
            if (s[start]==s[end]){
                maxlen = end - start + 1;
                --start; ++end;
            } else {
                break;
            }
        }
        if (maxlen > maxlen_last) {
            maxlen_last = maxlen;
            start_last = ++start;
        }
    }
    subs = s.substr(start_last, maxlen_last);
    return subs;
}
};

int main() {
    string sin;
    ifstream fp;
    fp.open("0005.txt");

    vector<string> vs;

    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
    }

    fp.close();

    for (int i=0; i<vs.size(); ++i) {
        string sss = longestPalindrome(vs[i]);
        printf("%s\n", sss.c_str());
    }

    return 0;
}