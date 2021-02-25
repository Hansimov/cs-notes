#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_fetch_times(const vector<int> &nums) {
    int n = nums.size();
    if (n==1) return 1;
    vector<int> dp(n,0);
    dp[0] = 1;
    for (int i=1; i<n; ++i) {
        bool flag = true;
        int a=-1, b=-1;
        for (int j=i; j>=0; --j) {
            if (a==-1) {
                a = nums[j];
                continue;
            } else if (nums[j]==a) {
                continue;
            } else if (b==-1) {
                b = nums[j];
                continue;
            } else if (nums[j]==b) {
                continue;
            } else {
                dp[i] = dp[i-1] + 1;
                break;
            }
            dp[i] = dp[i-1];
        }
    }
    for (auto const &ele: dp) {
        cout << ele << " ";
    }
    cout << endl;
    return dp[n-1];
}

int main() {
    vector<vector<int>> vv = {
        {1,2,2,3,3,3,4,5,6,5,5}, // 6
        {2,2,3,3,3,2,2},         // 2
        {3,2,4,2,3,2,4}          // 5
    };
    for (auto const &v: vv) {
        cout << get_fetch_times(v) << endl;
    }
    return 0;
}