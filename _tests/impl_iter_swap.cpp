#include <iostream>
#include <vector>
#include <algorithm> // swap, iter_swap
#include "_utils.h"

template <typename ForwardIter1, typename ForwardIter2>
void my_iter_swap(ForwardIter1 itr1, ForwardIter2 itr2) {
    std::swap(*itr1, *itr2);
}

int main() {
    std::vector<int> v = {1,2,3,4,5};
    disp_vec(v);
    my_iter_swap(v.begin(), v.end()-1);
    disp_vec(v);
}