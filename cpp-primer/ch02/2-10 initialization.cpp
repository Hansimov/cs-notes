#include <iostream>
#include <string>

std::string global_str;
int global_int;

int main() {
    int local_int;
    std::string local_str;

    std::cout << global_str << " " << global_int << std::endl;
    std::cout << local_int << " " << local_str << std::endl;
    
    return 0;
}