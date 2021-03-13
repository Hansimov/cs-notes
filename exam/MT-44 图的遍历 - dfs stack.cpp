#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stack>

using namespace std;

void leastPath(vector<vector<int>> &v, int n) {
    int depth = 0;
    vector<bool> visited(n+1, false);
    stack<int> s;
    s.push(1);
    visited[1] = true;
    while (s.size() > 0) {
        stack<int> tmp;
        while (s.size()>0) {
            auto idx = s.top();
            s.pop();
            for (auto ele: v[idx]) {
                if (!visited[ele]) {
                    visited[ele] = true;
                    tmp.push(ele);
                }
            }
        }
        s = tmp;
        ++depth;
    }
    int res = 2*(n-1) - depth + 1;
    
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