#include <iostream>

int main() {
    int *ip, i, &r=i;
    std::cout << " " << i << " " << r << std::endl;
    // RAND_INT, RAND_INT
    // if try to cout *ip, nothing will cout though

    int m, *mp = 0;
    // std::cout << m << " " << mp << " " << *mp << std::endl;
    std::cout << m << " " << mp << " " << std::endl;
    // RAND_INT, 0
    // if try to cout *ip, nothing will cout though

    return 0;
}