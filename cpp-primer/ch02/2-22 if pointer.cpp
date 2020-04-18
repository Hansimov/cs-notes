#include <iostream>

int main() {
    int i = 3;
    int* p = &i;

    std::cout << p << " " << *p << std::endl;
    // 0x61ff08 3
    if (p)
        std::cout << "p is not nullptr" << std::endl;
    // true
    if (*p)
        std::cout << "*p is not 0" << std::endl;
    // true

    int j = 0;
    int* q = &j;
    std::cout << q << " " << *q << std::endl;
    // 0x61ff08 3
    if (q)
        std::cout << "q is not nullptr" << std::endl;
    // true
    if (*q)
        std::cout << "*q is not 0" << std::endl;
    // false

    int *s;
    std::cout << s << " " << *s << std::endl;
    // 0x75f16fed 458873079
    if (s)
        std::cout << "s is not nullptr" << std::endl;
    // true
    if (*s)
        std::cout << "*s is not 0" << std::endl;
    // true

    int *t = 0;
    std::cout << t << " " << *t << std::endl;
    // (cout nothing)
    if (t)
        std::cout << "t is not nullptr" << std::endl;
    // false (cout nothing)
    if (*t)
        std::cout << "*t is 0" << std::endl;
    // false (cout nothing)

    return 0;
}