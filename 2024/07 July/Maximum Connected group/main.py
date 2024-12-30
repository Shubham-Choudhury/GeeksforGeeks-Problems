# Link: https://www.geeksforgeeks.org/problems/maximum-connected-group/1

from typing import List
from collections import defaultdict


class Solution:
    def __init__(self):
        self.x = [0, 0, 1, -1]
        self.y = [1, -1, 0, 0]

    def dfs(self, i, j, c, temp, n, m, grid, vis, mp):
        if i < 0 or i == n or j < 0 or j == m or grid[i][j] == 0 or vis[i][j]:
            return
        vis[i][j] = 1
        temp[0] += 1
        mp[i][j] = c
        for k in range(4):
            self.dfs(i + self.x[k], j + self.y[k], c, temp, n, m, grid, vis, mp)

    def fun(self, i, j, n, m, ans, mp, mpp):
        temp = 0
        s = set()
        for k in range(4):
            ni, nj = i + self.x[k], j + self.y[k]
            if 0 <= ni < n and 0 <= nj < m and mp[ni][nj] != -1:
                s.add(mp[ni][nj])
        for it in s:
            temp += mpp[it]
        ans[0] = max(ans[0], 1 + temp)

    def MaxConnection(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        ans = [0]
        vis = [[0] * m for _ in range(n)]
        mp = [[-1] * m for _ in range(n)]
        mpp = defaultdict(int)

        c = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and not vis[i][j]:
                    temp = [0]
                    self.dfs(i, j, c, temp, n, m, grid, vis, mp)
                    mpp[c] = temp[0]
                    c += 1

        for it in mpp.values():
            ans[0] = max(ans[0], it)

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    self.fun(i, j, n, m, ans, mp, mpp)

        return ans[0]


if __name__ == "__main__":
    obj = Solution()
    grid = [[1, 1], [0, 1]]
    print(obj.MaxConnection(grid))

    grid = [[1, 0, 1], [1, 0, 1], [1, 0, 1]]
    print(obj.MaxConnection(grid))
