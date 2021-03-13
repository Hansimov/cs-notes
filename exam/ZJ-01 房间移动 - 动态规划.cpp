#include <iostream>
#include <vector>

using namespace std;

int moveTimes(int n, vector<int> & p) {
    int mod = 1e9+7;
    vector<int> dp(n+1,0);
    dp[0] = 0;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> p(n,0);
        for (int i=0; i<n; ++i) {
            cin >> p[i];
            --p[i];
        }
        cout << moveTimes(n, p) << endl;
    }
    return 0;
}