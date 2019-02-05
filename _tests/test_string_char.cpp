#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string s = "abc";
    char c = 'a';
    string subs = "a";
    printf("%d\n", s[0]==c);
    printf("%d\n", s.substr(0,1)==subs);

    return 0;
}