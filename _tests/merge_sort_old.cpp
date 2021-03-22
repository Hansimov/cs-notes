#include "_utils.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void _merge_sort(vector<int>& arr, vector<int>& tmp, int b, int e) {
    if (b >= e)
        return ;
    // Divide and sort
    int b1 = b, e1 = b + (e-b)/2;
    int b2 = e1+1, e2 = e;
    _merge_sort(arr, tmp, b1, e1); // arr[b1:e1] is sorted
    _merge_sort(arr, tmp, b2, e2); // arr[b1:e2] is sorted
    // Merge
    int i = b;
    while (b1<=e1 && b2<=e2)
        tmp[i++] = (arr[b1] <= arr[b2]) ? arr[b1++] : arr[b2++];
    while (b1<=e1)
        tmp[i++] = arr[b1++];
    while (b2<=e2)
        tmp[i++] = arr[b2++];
    // copy(tmp.begin()+b, tmp.begin()+e+1, arr.begin()+b);
    for (int j=b; j<=e; ++j)
        arr[j] = tmp[j];
}

void merge_sort(vector<int>& arr) {
    vector<int> tmp(arr.size(), 0);
    _merge_sort(arr, tmp, 0, arr.size()-1);
}

int main() {
    vector<int> arr = {2,3,5,1,6,9,8,4,7};
    // vector<int> arr = {1,3,2,3,1};
    disp(arr);
    merge_sort(arr);
    disp(arr);

    return 0;
}
