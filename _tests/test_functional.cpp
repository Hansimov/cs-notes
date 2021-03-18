#include <iostream>
#include <functional>

using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    int a = 1;
    int b = 2;

    cout << cmp(a,b) << endl;
}