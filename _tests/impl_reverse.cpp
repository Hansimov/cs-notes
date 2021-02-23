#include <iostream>
#include <vector>
// #include <algorithm> // reverse


template <typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last) {
    while ((first!=last) && (first!=--last)) {
        std::iter_swap(first, last);
        ++first;
    }
}

void disp_vector(std::vector<int> & v) {
    for (auto const &ele:v)
        std::cout << ele << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {1,2,3,4,5};
    disp_vector(v);
    my_reverse(v.begin(), v.end());
    disp_vector(v);
    return 0;
}