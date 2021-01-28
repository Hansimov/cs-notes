class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int next = 0;
            while (num > 0) {
                next += num % 10;
                num = num / 10;
            }
            num = next;
        }
        return num;
    }
};