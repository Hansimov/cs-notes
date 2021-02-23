#include <vector>
#include "_utils.h"

template <typename ForwardIter>
void my_rotate(ForwardIter first, ForwardIter mid, ForwardIter last) {
    ForwardIter next = mid;
    while (first != next) {
    // `first != last` is also corrected, but more swaps
        std::swap(*first++, *next++);
        if (next == last)      // right of mid processed
            next = mid;
        else if (first == mid) // left of mid processed
            mid = next;
    }
}

int main() {
    // roate left
    std::vector<int> v1 = {1,2,3,4,5};
    my_rotate(v1.begin(), v1.begin()+3, v1.end());
    disp(v1);

    // rotate right
    std::vector<int> v2 = {1,2,3,4,5};
    my_rotate(v2.rbegin(), v2.rbegin()+3, v2.rend());
    disp(v2);

    return 0;
}