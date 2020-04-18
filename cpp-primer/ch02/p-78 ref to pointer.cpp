#include <iostream>

int main() {
    int i = 14;
    int *p;
    int *&r = p;

    r = &i;
    std::cout << r << " " << p << " " << i << std::endl;
    // 0x61fef8 0x61fef8 14
    std::cout << *r << " " << *p << " " << i << std::endl;
    // 14 14 14

    *r = 3;
    std::cout << r << " " << p << " " << i << std::endl;
    // 0x61fef8 0x61fef8 14
    std::cout << *r << " " << *p << " " << i << std::endl;
    // 3 3 3

    return 0;
}