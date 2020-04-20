#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    const string s = "Keep out!";

    for (auto &c : s)
        cout << c;
    // c: const char &
    cout << endl;

    return 0;
}