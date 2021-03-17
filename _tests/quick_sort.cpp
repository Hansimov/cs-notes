#include "_utils.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int rand_partition(vector<int> &a, int L, int R) {
    int pivot = rand() % (R-L+1) + L;
    swap(a[pivot], a[R]);
    int last = a[R];
    int i=L;
    for (int j=L; j<R; ++j) {
        if (a[j] < last)
            swap(a[j], a[i++]);
    }
    swap(a[i], a[R]);
    return i;
}

void _quick_sort(vector<int> & a, int L, int R) {
    if (L<R) {
        int q = rand_partition(a, L, R);
        _quick_sort(a, L, q-1);
        _quick_sort(a, q+1, R);
    }
}

void quick_sort(vector<int> & a) {
    _quick_sort(a, 0, a.size()-1);
}

int main() {
    vector<int> nums = {2,3,5,6,4,7,1,0};
    disp(nums);
    quick_sort(nums);
    disp(nums);
   
    return 0;
}