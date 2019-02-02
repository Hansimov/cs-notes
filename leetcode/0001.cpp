#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int, int> val_idx_map;
    for (int i=0; i<nums.size(); ++i) {
        if (val_idx_map.find(target-nums[i]) != val_idx_map.end()){
            return vector<int> {val_idx_map[target-nums[i]], i};
        } else {
            val_idx_map[nums[i]] = i;
        }
    }
    return vector<int> {0,0};
}

int main() {
    FILE * fp = fopen("0001.txt", "r");
    int sz, n, target;
    vector<int> nums;
    fscanf(fp, "%d", &sz);
    for (int i=0; i<sz; ++i) {
        fscanf(fp, "%d", &n);
        nums.push_back(n);
    }
    fscanf(fp, "%d", &target);

    vector<int> res;
    res = twoSum(nums, target);
    for (int i=0; i<res.size(); ++i) {
        printf("%d ", res[i]);
    }

    return 0;
}