#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stack>

using namespace std;

int depth = 0;
int sum = 0;

void dfs(vector<vector<int>> &v, int n, int x, int pre, int depth) {
    for (int i=0; i<v[x].size(); ++i) {
        if (v[x][i]!=pre)
            dfs(v, n, v[x][i], x, depth+1);
    }
    sum = max(sum, depth);
}

void leastPath(vector<vector<int>> &v, int n) {
    dfs(v, n, 1, -1, depth);
    int res = 2*(n-1) - sum;
    cout << res << endl;
}

int main(){
    // freopen("MT-44.txt", "r", stdin);
    int n, x, y;
    while (cin >> n) {
        vector<vector<int>> v(n+1);
        for (int i=0; i<n-1; ++i) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        leastPath(v, n);
    }

    return 0;
}