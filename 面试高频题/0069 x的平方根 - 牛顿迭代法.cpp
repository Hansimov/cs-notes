class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        double C = x, x_old = x, x_new;
        while (1) {
            x_new = 0.5 * (x_old + C/x_old);
            if (fabs(x_new - x_old) < 1e-7)
                break;
            x_old = x_new;
        }
        return int(x_old);
    }
};