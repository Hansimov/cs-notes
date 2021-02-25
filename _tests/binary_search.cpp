#include "_utils.h"

// return index of target, if none, return -1
int my_binary_search(const std::vector<int> & nums, int target) {
    int left = 0;
    int right = nums.size();
    int mid;

    while (left < right) { // search through [left, right)
        mid = left + (right-left)/2; // prevent overflow
        if (nums[mid]==target)
            return mid;
        else if (nums[mid]<target)
            left = mid + 1;
        else
            right = mid;
    }
    return -1;
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7};
    disp(my_binary_search(v,4));
    disp(my_binary_search(v,8));
    disp(my_binary_search(v,-1));
    std::vector<int> v2 = {1,1};
    disp(my_binary_search(v2,0));
    return 0;
}