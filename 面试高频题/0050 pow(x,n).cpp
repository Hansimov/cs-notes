class Solution {
public:
    double myPow(double x, int n) {
        if (x==0)
            return 0;
        double res=1;
        if (n<0) {
            if (n==INT_MIN) { // 最小的负数会溢出
                return myPow(x,n+1) * x;
            } else {
                x = 1/x;
                n = -n;
            }
        }
        while (n) {
            if (n&1) { // 如果该位为 1，则将 res 乘上此时的 x
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};