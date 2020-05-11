#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int local_func(int a) {
    int b = 10;
    static int c = 0;
    c += 100;
    return a + b + c;
}

int main() {
    for (int i=0; i<5; ++i) {
        cout << local_func(i) << endl;
        // 110 211 312 413 514
    }

    return 0;
}