#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1("hello"),
           s2("hello "),
           s3("HELLO");
    // Dict Order: A-Z < a-z < 0-9
    if (s1<s2)
        cout << s1 << endl;
    else
        cout << s2 << endl;

    if (s1<s3)
        cout << s1 << endl;
    else
        cout << s3 << endl;

    return 0;
}