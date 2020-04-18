#include <iostream>

int main() {
    std::cout << "Hi \x4dO\115!\n";
    std::cout << '\115' << '\n';
    std::cout << "\1234" << "\x1234" << "\n";
    // '\x123' will raise warning: hex escape sequence out of range
    
    return 0;
}