/*
- 花式求解 LeetCode 279题－Perfect Squares - 简书 
    https://www.jianshu.com/p/2925f4d7511b
- 4ms C++ code - Solve it mathematically - LeetCode Discuss 
    https://leetcode.com/problems/perfect-squares/discuss/71618/4ms-C%2B%2B-code-Solve-it-mathematically
- Lagrange's four-square theorem - Wikipedia 
    https://en.wikipedia.org/wiki/Lagrange's_four-square_theorem
- Legendre's three-square theorem - Wikipedia 
    https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
- Lagrange's Four-Square Theorem -- from Wolfram MathWorld 
    http://mathworld.wolfram.com/LagrangesFour-SquareTheorem.html
- [LeetCode] 279. Perfect Squares 完全平方数 - Grandyang - 博客园 
    https://www.cnblogs.com/grandyang/p/4800552.html
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isSquare(int k) {
    return (k == (int)sqrt(k) * (int)sqrt(k));
}

int numSquares(int n) {
    if (n<=0) return 0;
    
    if (isSquare(n)) return 1;
    
    while (n%4==0) {
        n /= 4;
    }

    if (n%8==7) return 4;

    for (int i=1; i<=(int)sqrt(n); ++i) {
        if (isSquare(n-i*i))
            return 2;
    }

    return 3;
}

int main() {
    string sin;
    int n, r;
    vector<int> vn, vr;

    ifstream fp;
    fp.open("0279.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> n >> r;
        vn.push_back(n);
        vr.push_back(r);
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int correct_cnt=0;
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = numSquares(vn[i]);
        bool is_correct = res==vr[i];
        printf("%d\t%d\t%d\t%d\t\n", is_correct, line, vr[i], res);
        if (is_correct) ++correct_cnt;
        line += 1;
    }
    printf("--- --- --- --- \n");
    printf("%d/%d\n", correct_cnt, vr.size());

    return 0;
}