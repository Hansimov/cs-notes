#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print_arr(const vector<int> & arr) {
    for (auto const &ele: arr)
        cout << ele << " ";
    cout << endl;
}

void merge_sort_sub(vector<int>& arr, vector<int>& tmp, int b, int e) {
    if (b >= e)
        return ;
    // Divide and sort
    int b1 = b, e1 = b + (e-b)/2;
    int b2 = e1+1, e2 = e;
    merge_sort_sub(arr, tmp, b1, e1); // arr[b1:e1] is sorted
    merge_sort_sub(arr, tmp, b2, e2); // arr[b1:e2] is sorted
    // Merge
    int i = b;
    while (b1<=e1 && b2<=e2)
        tmp[i++] = arr[b1] <= arr[b2] ? arr[b1++] : arr[b2++];
    while (b1<=e1)
        tmp[i++] = arr[b1++];
    while (b2<=e2)
        tmp[i++] = arr[b2++];
    // for (int j=b; j<=e; ++j)
    //     arr[j] = tmp[j];
    copy(tmp.begin()+b, tmp.begin()+e+1, arr.begin()+b);
}

void merge_sort(vector<int>& arr) {
    vector<int> tmp(arr.size(), 0);
    merge_sort_sub(arr, tmp, 0, arr.size()-1);
}

int main() {
    // vector<int> arr = {2,3,5,1,6,9,8,4,7};
    vector<int> arr = {1,3,2,3,1};
    print_arr(arr);
    merge_sort(arr);
    print_arr(arr);

    return 0;
}
