class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (auto n: nums)
            tmp ^= n;
        int sep = 1;
        while ((sep & tmp) == 0)
            sep <<= 1;
        int a = 0, b = 0;
        for (auto n: nums)
            if (sep & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};