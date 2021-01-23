class Solution {
public:
    int squareSum(int x) {
        int sum = 0;
        while (x>0) {
            sum += (x%10) * (x%10); // 注意加上括号，运算优先级
            x /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        } while (slow != fast);
        return slow == 1;
    }
};