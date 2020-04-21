#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl; // 10
    cout << sizeof(p) / sizeof(*p) << endl; // 4/4=1
    // int *: 4 bytes (on 32-bit machine, 8 bytes on 64-bit)
    // int  : 4 bytes (on 32-bit machine, 8 bytes on 64-bit)

    return 0;
}