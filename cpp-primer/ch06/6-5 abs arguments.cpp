#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
T abs_arg(T x) {
    return x<0?-x:x;
}

int main() {
    cout << abs_arg(1) << endl;
    cout << abs_arg(0) << endl;
    cout << abs_arg(-1) << endl;
    cout << abs_arg(1.1) << endl;
    cout << abs_arg(-1.1) << endl;

    return 0;
}