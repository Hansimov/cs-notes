#include <iostream>

int main() {
    int ival = 42;
    int *p = &ival;
    std::cout << *p << " " << ival << std::endl;
    // 42 42

    *p = 3;
    std::cout << *p << " " << ival << std::endl;
    // 3 3

    return 0;
}