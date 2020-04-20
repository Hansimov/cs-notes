#include <iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

int main() {
    string s("hello 123!");

    for (char &c: s)
    // for (auto &c: s)
        c = 'X';
    cout << s.size() <<" "<< s << endl;

    return 0;
}