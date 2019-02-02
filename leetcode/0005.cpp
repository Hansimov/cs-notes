// Longest Palindromic Substring - GeeksforGeeks
//   https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
    if (s[0] == s[s.size()-1]) {
        return true;
    } else {
        return false;
    }
}

string subLongestPalindrome(vector<vector<int>> v_old, string s) {
    int start, end, maxlen;
    vector<vector<int>> v_new = {};
    string ss, subs;

    if (v_old.empty()) {
        subs = "";
        return subs;
    }


    while (true) {
        maxlen = v_old[0][1];
        for (int i=0; i<v_old.size(); ++i) {
            start = v_old[i][0];
            end = start + maxlen - 1;
            if (start-1>=0 && end+1<=s.size()-1) {
                ss = s.substr(start-1, maxlen+2);
                if (isPalindrome(ss)) {
                    v_new.push_back({start-1, maxlen+2});
                }
            }
        }
        if (v_new.empty()) {
            break;
        } else {
            v_old = v_new;
            v_new = {};
            maxlen += 2;
        }
    }

    subs = s.substr(v_old[0][0], v_old[0][1]);

    return subs;
}

class Solution {
public:
string longestPalindrome(string s) {
    vector<vector<int>> init_v_odd = {};
    vector<vector<int>> init_v_even = {};

    string subs;
    if (s.size()<=1){
        subs = s;
        return subs;
    } else if (s.size()==2) {
        if (s[0]==s[1]){
            subs = s;
        } else {
            subs = s[0];
        }
        return subs;
    }

    for (int i=0; i<s.size(); ++i) {
        if (i>=0 && i<=s.size()-1) {
            init_v_odd.push_back({i,1});
        }
        if (i>=0 && i+1<=s.size()-1) {
            if (s[i]==s[i+1]){
                init_v_even.push_back({i,2});
            }
        }
    }


    string subs_odd, subs_even;

    subs_odd = subLongestPalindrome(init_v_odd, s);
    subs_even = subLongestPalindrome(init_v_even, s);

    if (subs_odd.size() > subs_even.size()){
        return subs_odd;
    } else {
        return subs_even;
    }
}
};

int main() {
    string sin;
    // FILE * fp = fopen("0005.txt", "r");
    ifstream fp;
    fp.open("0005.txt");

    vector<string> vs;

    while (getline(fp, sin, '\n')) {
        // printf("%s\n", sin.c_str());
        vs.push_back(sin);
    }

    fp.close();

    for (int i=0; i<vs.size(); ++i) {
        string sss = longestPalindrome(vs[i]);
        printf("%s\n", sss.c_str());
    }

    return 0;
}