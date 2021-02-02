class Solution {
public:
    int translateNum(int num) {
        if (num<10)
            return 1;
        if (num%100<26 && num%100>9)
            return translateNum(num/10) + translateNum(num/100);
        else
            return translateNum(num/10);
    }
};