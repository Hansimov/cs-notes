#include "_utils.h"

#include <iostream>
#include <vector>

void _merge_sort(vector<int>&a, vector<int>& tmp, int b, int e) {
    if (b>=e) return;
    
}

int main() {
    vector<int> arr = {2,3,5,1,6,9,8,4,7};
    disp(arr);
    merge_sort(arr);
    disp(arr);
    return 0;
}