#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void swap_by_ptr(int *a, int *b) {
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_by_ref(int &a, int &b) {
    auto tmp = a;
    a = b;
    b = tmp;
}

int main() {
    
    int a = 1, b = 2;
    swap_by_ptr(&a, &b);
    cout << a << " " << b << endl;
    swap_by_ref(a, b);
    cout << a << " " << b << endl;

    return 0;
}