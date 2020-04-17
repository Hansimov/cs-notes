#include <iostream>

int main() {
    std::cout << "/*"; // ok
    std::cout << "*/"; // ok
    // std::cout << /* "*/" */; // error
    std::cout << /* "*/" /* "/*" */; // ok
}