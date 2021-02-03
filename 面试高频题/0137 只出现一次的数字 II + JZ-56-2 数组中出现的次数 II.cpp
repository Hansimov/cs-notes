class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<32; ++i) {
            int cnt=0;
            for (auto const &n: nums) // count number of 1 at i-th bit
                if (n & (1<<i)) // i-th bit of n is 1
                    ++cnt;
            if (cnt % 3 == 1)  // set i-th bit to 1
                res |= (1<<i);
        }
        return res;
    }
};