#include "_utils.h"
#include <vector>
#include <algorithm>  // lower_bound, upper_bound
#include <cstdio>     // printf 

using namespace std;

int main() {
    // 数组 v 必须有序，且从小到大排列
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    int p = 4;
    // 二分查找 不小于 p 的第一个元素
    int L1 = lower_bound(v.begin(), v.end(), p) - v.begin();    // 4
    // 二分查找 不小于 p 的第一个元素，与上一种等价
    int U2 = v.rend() - upper_bound(v.rbegin(), v.rend(), p, greater<int>()); // 4

    // 二分查找 大于 p 的第一个元素
    int U1 = upper_bound(v.begin(), v.end(), p) - v.begin(); // 5
    // 二分查找 大于 p 的第一个元素，与上一种等价
    int L2 = v.rend() - lower_bound(v.rbegin(), v.rend(), p, greater<int>()); // 5

    printf("%d %d %d %d \n", L1, U2, U1, L2);
    
    // 二分查找 小于 p 的（从右向左）第一个元素
    int L3 = lower_bound(v.begin(), v.end(), p) - v.begin() -1; // 3
    // 二分查找 不大于 p 的（从右向左）第一个元素
    int U3 = upper_bound(v.begin(), v.end(), p) - v.begin() -1; // 4
    
    printf("%d %d \n", L3, U3);

    return 0;
}