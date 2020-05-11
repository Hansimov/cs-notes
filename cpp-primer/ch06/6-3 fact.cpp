#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fact(int n) {
    int res = 1;
    for (int i=1; i<=n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    cout << fact(5) << endl;

    return 0;
}