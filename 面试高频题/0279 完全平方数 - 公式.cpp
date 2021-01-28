class Solution {
public:
    bool isSquare(int x) {
        int sq = int(sqrt(x));
        return sq*sq==x;
    }
    int numSquares(int n) {
        while (n%4==0)
            n>>=2;
        if (n%8==7)
            return 4;
        if (isSquare(n))
            return 1;
        for (int i=1; i<=int(sqrt(n)); ++i){
            if (isSquare(n-i*i))
                return 2;
        }
        return 3;
    }
};