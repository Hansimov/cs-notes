#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        vector<int> d;
        int len = 1;
        d.push_back(nums[0]);
        for (int i=1; i<n; ++i) {
            if (nums[i] > d[len-1]) {
                d.push_back(nums[i]);
                ++len;
            } else {
                // find (from-right-to-left) first d[i] that less than nums[i]
                // int k = lower_bound(d.begin(), d.end(), nums[i])-d.begin()-1;
                int L=0, R=len, mid;
                while (L<R) { // search in [L,R)
                    mid = L+(R-L)/2;
                    if (d[mid]<nums[i])
                        L = mid+1;
                    else
                        R = mid;
                }
                L = L-1;
                ////
                d[L+1] = nums[i];
            }
        }
        return len;
    }
};

int main() {
    Solution sol;
    // vector<int> v = {10,9,2,5,3,7,101,18};
    vector<int> v = {7,7,7,7,7};
    int len = sol.lengthOfLIS(v);
    printf("%d\n", len);
    return 0;
}