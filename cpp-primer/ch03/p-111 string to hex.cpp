#include <iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

int main() {
    const string hex_chrs = "0123456789ABCDEF";
    string res;
    string::size_type n;
    while (cin >> n)
        if (n<hex_chrs.size())
            res += hex_chrs[n];

    cout << res << endl;

    return 0;
}