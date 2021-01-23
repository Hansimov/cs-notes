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
        unordered_set<int> set;
        while (1) {
            if (n==1)
                return true;
            n = squareSum(n);
            if (set.find(n) != set.end()) {
                return false;
            } else {
                set.insert(n);
            }
        }
    }
};