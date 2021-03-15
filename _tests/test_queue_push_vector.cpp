#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    queue<vector<int>> q;
    q.push({1,2});
    auto tmp = q.front();
    
    cout << tmp[0] << " " << tmp[1] << endl;

    return 0;
}