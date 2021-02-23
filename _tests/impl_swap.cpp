#include <iostream>
#include <algorithm> // swap
#include "_utils.h"

template <typename T>
void my_swap (T& a, T& b) {
    T c(a);
    a = b;
    b = c;
}

int main() {
    int x = 1, y = 2;
    disp(x,y);
    my_swap(x, y);
    disp(x,y);
    return 0;
}