#include <iostream>

int main() {
    int i = 14;
    int *p = &i;
    *p = *p * *p;
    std::cout << *p << " " << i << std::endl;
    // 196 196

    return 0;
}