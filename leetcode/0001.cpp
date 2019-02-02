#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int isInVector(vector<int> v, int ele){
    for (int i=0; i<v.size(); ++i) {
        if (v[i] == ele){
            return i;
        }
    }
    return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res = {0, 0};
    vector<int> hash;
    int idx;
    for (int i=0; i<nums.size(); ++i) {
        idx = isInVector(hash, target-nums[i]);
        if (idx != -1){
            res[0] = idx;
            res[1] = i;
            return res;
        } else {
            hash.push_back(nums[i]);
        }
    }
    return res;
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