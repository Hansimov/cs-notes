from typing import List
import collections

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def bfs(grid,i,j):
            q = collections.deque()
            q.append((i,j))
            while q:
                i, j = q.popleft()
                if 0<=i<len(grid) and 0<=j<len(grid[0]) and grid[i][j]=='1':
                    grid[i][j] = '0'
                    q.extend([(i-1,j), (i+1,j), (i,j-1), (i,j+1)])
            cnt = 0
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == '0':
                        continue
                    bfs(grid, i, j)
                    cnt += 1
            return cnt
