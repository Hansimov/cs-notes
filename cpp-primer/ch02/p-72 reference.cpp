#include <iostream>

int main() {
    int i_val = 1024;
    int & ref_val = i_val;
    ref_val = 2;

    std::cout << i_val << " " << ref_val << std::endl;

    return 0;
}