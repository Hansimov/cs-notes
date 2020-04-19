#include <iostream>
#include <string>

struct Sales_data {
    std::string isbn = {"C++ Primer"};
    unsigned units_sold = 2;
    double revenue = 3.4;
};

int main() {
    
    Sales_data sd;
    std::cout << sd.units_sold << " " << sd.revenue << " " << sd.isbn << std::endl;
    
    return 0;
}