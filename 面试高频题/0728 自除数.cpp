class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int num=left; num<=right; ++num) {
            int tmp = num;
            int mod = 0;
            while (tmp!=0) {
                mod = tmp % 10;
                if (mod==0 || num%mod!=0)
                    break;
                tmp /= 10;
            }
            if (tmp==0)
                res.push_back(num);
        }
        return res;
    }
};