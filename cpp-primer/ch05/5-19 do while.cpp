#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1,s2,rsp;
    do {
        cout << "Please input two strings: ";

        cin >> s1 >> s2;
        cout << s1 << " " << s2 << endl;

        cout << (s1<=s2 ? s1 : s2) << endl;

        cout << "Continue inputing? (y/n) ";
        cin >> rsp;
        cout << rsp << endl;
    } while (!rsp.empty() && rsp[0]=='y');

    return 0;
}