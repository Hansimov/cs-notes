#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
bool isValid(string s) {
    if (s.size() == 0) {
        return true;
    }

    stack<char> t;
    for (int i=0; i<s.size(); ++i) {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
            t.push(s[i]);
        } else {
            if (t.empty()) {
                return false;
            } else {
                if ( (s[i]==')' && t.top()=='(') || (s[i]==']' && t.top()=='[') || (s[i]=='}' && t.top()=='{') ) {
                    t.pop();
                } else {
                    return false;
                }
            }
        }
    }
    if (t.empty()) {
        return true;
    } else {
        return false;
    }
}
};


int main() {
    string sin;
    vector<string> vs;

    ifstream fp;
    fp.open("0020.txt");

    while (getline(fp, sin, '\n')) {
        vs.push_back(sin);
    }
    fp.close();

    for (int i=0; i<vs.size(); ++i) {
        bool b = isValid(vs[i]);
        printf("%s\n", b?"true":"false");
    }

    return 0;
}