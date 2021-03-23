#include "_utils.h"

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

bool cmp(int a, int b) {
    return a < b; // max heap
}

void heapify(vector<int> &nums, int i, int r_bound, bool (*cmp)(int, int)) {
    while (i*2+1 <= r_bound) { // left child is not null
        int L = i*2 + 1;
        int R = i*2 + 2;
        int greater_idx;

        // get greater child idx; 
        if (L<=r_bound && cmp(nums[i], nums[L]))
            greater_idx = L;
        else
            greater_idx = i;
        if (R<=r_bound && cmp(nums[greater_idx], nums[R]))
            greater_idx = R;

        // if greater than both child, break
        // else swap to greater child, and adjust the new child
        if (greater_idx == i) 
            break;
        else {
            swap(nums[greater_idx], nums[i]);
            i = greater_idx;
        }
    }
}

void build_heap(vector<int> &nums, bool (*cmp)(int, int)) {
    int len = nums.size();
    for (int i=(len-1)/2; i>=0; --i) {
        heapify(nums, i, len-1, cmp);
    }
}

void heap_sort(vector<int> &nums, bool (*cmp)(int,int)) {
    build_heap(nums, cmp);
    disp(nums);
    int len = nums.size();
    for (int i = len-1; i>=1; --i) {
        swap(nums[0], nums[i]);
        heapify(nums, 0, i-1, cmp);
    }
}

int main() {
    vector<int> nums = {4,6,3,7,8,5,9,1,2};
    disp(nums);
    heap_sort(nums, [](int a, int b){ return a < b;});
    disp(nums);

    return 0;
}