# Link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1


class Solution:
    def numIslands(self, grid):
        directions = (
            (0, 1),
            (0, -1),
            (1, 0),
            (-1, 0),
            (1, 1),
            (1, -1),
            (-1, 1),
            (-1, -1),
        )
        n = len(grid)
        m = len(grid[0])
        total = 0

        def dfs(x, y):
            grid[x][y] = 0
            for i, j in directions:
                if 0 <= x + i < n and 0 <= y + j < m and grid[x + i][y + j] != 0:
                    dfs(x + i, y + j)

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    dfs(i, j)
                    total += 1
        return total


if __name__ == "__main__":
    obj = Solution()
    grid = [["0", "1"], ["1", "0"], ["1", "1"], ["1", "0"]]
    print(obj.numIslands(grid))

    grid = [["0", "1", "1", "1", "0", "0", "0"], ["0", "0", "1", "1", "0", "1", "0"]]
    print(obj.numIslands(grid))
