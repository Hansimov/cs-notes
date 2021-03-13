/*
由题意得：n个点，n-1条边组成得图是无环图，所以要遍历所有点，最少得走法是所有边走两遍，再减去图中的最长路径
因此本题可以理解为，用bfs求图的最长路径
*/

#include <bits/stdc++.h>
using namespace std;

int sum = 0;
const int N = 100003;
vector<int> v[N];

void DFS(int x, int pre, int w) {
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] != pre)
            DFS(v[x][i], x, w + 1);
    }
    sum = max(sum, w);
}

int main() {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1, -1, 0);
    cout << 2 * (n - 1) - sum << endl;
    return 0;
}