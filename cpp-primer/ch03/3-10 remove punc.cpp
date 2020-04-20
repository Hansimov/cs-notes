#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string s = "hello, world! ";

    for (auto c: s)
        if (!ispunct(c))
            cout << c;
    cout << endl;

    return 0;
}