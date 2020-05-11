#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void f() {
    cout << __func__ << endl;
}

void f(int x) {
    cout << __func__ << ":" << x << endl;
}

void f(int x, int y) {
    cout << __func__ << ":" << x << " " << y << endl;
}

void f(double x, double y=3.14) {
    cout << __func__ << ":" << x << " " << y << endl;
}

int main() {
    f();
    f(1);
    f(2,3);
    f(4.0);

    return 0;
}