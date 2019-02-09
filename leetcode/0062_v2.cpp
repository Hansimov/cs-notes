#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
// #include <utility>

using namespace std;

static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
int uniquePaths(int m, int n) {
    if (m==0 || n==0) return 0;
    // C(m+n-2, n-1) = (m+n-2)! / (n-1)! / (m-1)!
    //   = (m+n-2)*...*m / (n-1)!
    int N, K;
    double res = 1;
    N = m+n-2;
    if (m>n) K=n-1; else K=m-1;
    for (int i=0; i<K; ++i) {
        res *= (N-i);
    }
    for (int i=0; i<K; ++i) {
        res /= (i+1);
    }

    return (int)res;
}
};

int main() {
    string sin;
    int m, n, rin;
    vector<int> vm, vn, vr;

    ifstream fp;
    fp.open("0062.txt");

    int d;
    int c=0;
    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> m >> n >> rin;
        vm.push_back(m);
        vn.push_back(n);
        vr.push_back(rin);
        // printf("%s %s\n", rin.c_str(), pin.c_str());
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    for (int i=0; i<vm.size(); ++i) {
        int r = uniquePaths(vm[i], vn[i]);
        printf("%d\t%d\t%d\t%d\t\n", r==vr[i], i+1, vr[i], r);
    }

    return 0;
}