class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int low = 0, high = x;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if ((long long) mid*mid <= x) { // 防止整型溢出，做乘法时转成 long long
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};