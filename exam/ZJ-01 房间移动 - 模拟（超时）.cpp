#include <iostream>
#include <vector>

using namespace std;

int moveTimes(int n, vector<int> & p) {
    vector<bool> visit(n, 0); // init with even num
    visit[0] = 1;
    int idx = 0;
    int cnt = 0;
    while (idx<n) {
        if (visit[idx]==0) {
            ++idx;
        } else {
            idx = p[idx];
        }
        visit[idx] = !visit[idx];
        ++cnt;
    }
    return cnt;
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