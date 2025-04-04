# Link: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1


class Solution:
    def numIslands(self, grid):
        m, n = len(grid), len(grid[0])

        def dfs(r, c):
            nonlocal m, n
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == "W":
                return
            grid[r][c] = "W"
            for dr in (-1, 0, 1):
                for dc in (-1, 0, 1):
                    if dr == 0 and dc == 0:
                        continue
                    dfs(r + dr, c + dc)

        cnt = 0
        for i, r in enumerate(grid):
            for j, e in enumerate(r):
                if e == "L":
                    cnt += 1
                    dfs(i, j)
        return cnt


if __name__ == "__main__":
    s = Solution()
    grid = [
        ["L", "L", "W", "W", "W"],
        ["W", "L", "W", "W", "L"],
        ["L", "W", "W", "L", "L"],
        ["W", "W", "W", "W", "W"],
        ["L", "W", "L", "L", "W"],
    ]
    print(s.numIslands(grid))

    grid = [
        ["W", "L", "L", "L", "W", "W", "W"],
        ["W", "W", "L", "L", "W", "L", "W"],
    ]
    print(s.numIslands(grid))
