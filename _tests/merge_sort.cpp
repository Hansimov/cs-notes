#include "_utils.h"

#include <iostream>
#include <vector>

using namespace std;

void _merge_sort(vector<int>&a, vector<int>& tmp, int b, int e) {
    if (b>=e) return;
    // Divide and sort
    int b1 = b, e1 = b+(e-b)/2;
    int b2 = e1+1, e2=e;
    _merge_sort(a, tmp, b1, e1);
    _merge_sort(a, tmp, b2, e2);
    // merge
    int i = b;
    while (b1<=e1 && b2<=e2)
        tmp[i++] = (a[b1]<=a[b2]) ? a[b1++] : a[b2++];
    while (b1<=e1)
        tmp[i++] = a[b1++];
    while (b2<=e2)
        tmp[i++] = a[b2++];
    for (int i=b; i<=e; ++i)
        a[i] = tmp[i];
}

void merge_sort(vector<int> &a) {
    vector<int> tmp(a.size());
    _merge_sort(a, tmp, 0, a.size()-1);
}

int main() {
    vector<int> arr = {2,3,5,1,6,9,8,4,7};
    disp(arr);
    merge_sort(arr);
    disp(arr);
    return 0;
}