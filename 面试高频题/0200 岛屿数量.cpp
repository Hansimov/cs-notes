#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<char>> g;
    vector<vector<int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
    void bfs(int i, int j) {
        queue<vector<int>> q;
        q.push({i,j});
        while (!q.empty()) {
            vector<int> tmp = q.front();
            q.pop();
            i=tmp[0], j=tmp[1];
            if (i>=0 && i<g.size() && j>=0 && j<g[0].size() && g[i][j] == '1') {
                g[i][j] = '0';
                for (auto const &x: d)
                    q.push({i+x[0], j+x[1]});
            }
            // g[i][j]='0';
            // for (auto const &x: d) {
            //     int ni=i+x[0], nj=j+x[1];
            //     if (ni>=0 && ni<g.size() && nj>=0 && nj<g[0].size() && g[ni][nj] == '1')
            //         q.push({ni,nj});
            // }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int res = 0;
        g = grid;
        int rowNum = g.size();
        int colNum = g[0].size();
        for (int i=0; i<rowNum; ++i) {
            for (int j=0; j<colNum; ++j) {
                if (g[i][j] == '0')
                    continue;
                bfs(i, j);
                ++res;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'0','1','0','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','1'},
        {'0','0','0','1','1'}
    };

    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution sol;
    cout << sol.numIslands(grid) << endl;
    
    return 0;
}