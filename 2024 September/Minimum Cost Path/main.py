# Link: https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

import heapq


class Solution:
    def minimumCostPath(self, grid):
        n = len(grid)
        m = len(grid[0])
        vis = [[float("inf")] * m for _ in range(n)]
        vis[0][0] = grid[0][0]
        pq = [(grid[0][0], 0, 0)]
        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]

        while pq:
            wt, row, col = heapq.heappop(pq)
            for dr, dc in directions:
                nr, nc = row + dr, col + dc
                if 0 <= nr < n and 0 <= nc < m:
                    if wt + grid[nr][nc] < vis[nr][nc]:
                        vis[nr][nc] = wt + grid[nr][nc]
                        heapq.heappush(pq, (vis[nr][nc], nr, nc))

        return vis[n - 1][m - 1]


if __name__ == "__main__":
    obj = Solution()
    grid = [[9, 4, 9, 9], [6, 7, 6, 4], [8, 3, 3, 7], [7, 4, 9, 10]]
    print(obj.minimumCostPath(grid))

    grid = [[4, 4], [3, 7]]
    print(obj.minimumCostPath(grid))
