#include <iostream>

int reused = 42;
int main() {
    int unique = 1;

    std::cout << reused << " " << unique << std::endl;
    // 42 1

    int reused = 3;
    std::cout << reused << " " << unique << std::endl;
    // 3 1

    std::cout << ::reused << " " << unique << std::endl;
    // 42 1
    
    return 0;
}