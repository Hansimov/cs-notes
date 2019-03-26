// std::string::find
//   http://www.cplusplus.com/reference/string/string/find/

#include <iostream>
#include <string>

using namespace std;

int main () {
    string s = "hello";
    char c = 'o';
    if (s.find(c) == string::npos)
        cout << "Not Found" << endl;
    else
        cout << s.find(c) << endl;
    // printf("%d\n", s.find(c));

    // cout << s.find(s[4]) << endl;

    return 0;
}