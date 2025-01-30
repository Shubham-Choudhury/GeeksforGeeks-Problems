# Link: https://www.geeksforgeeks.org/problems/n-queen-problem0315/1


class Solution:
    def __init__(self):
        self.ans = []

    def check(self, i, j, n, grid):
        for col in range(j):
            if grid[i][col] == 1:
                return False
        for row in range(i):
            if grid[row][j] == 1:
                return False

        a, b = i, j
        while a > -1 and b > -1:
            a -= 1
            b -= 1
            if a > -1 and b > -1:
                if grid[a][b] == 1:
                    return False

        a, b = i, j
        while a > -1 and a < n and b > -1 and b < n:
            a += 1
            b -= 1
            if a > -1 and a < n and b > -1 and b < n:
                if grid[a][b] == 1:
                    return False

        return True

    def backtrack(self, col, grid, path, n):
        if len(path) == n:
            self.ans.append(path.copy())
            return

        for i in range(n):
            if self.check(i, col, n, grid):
                grid[i][col] = 1
                path.append(i + 1)
                self.backtrack(col + 1, grid, path, n)
                grid[i][col] = 0
                path.pop()

    def nQueen(self, n):
        if n == 1:
            return [[1]]

        grid = [[0] * n for _ in range(n)]
        path = []
        self.backtrack(0, grid, path, n)
        if not self.ans:
            return []
        return self.ans


if __name__ == "__main__":
    solution = Solution()
    n = 1
    ans = solution.nQueen(n)
    for row in ans:
        print(" ".join(map(str, row)))
    print()

    n = 4
    ans = solution.nQueen(n)
    for row in ans:
        print(" ".join(map(str, row)))
    print()

    n = 2
    ans = solution.nQueen(n)
    for row in ans:
        print(" ".join(map(str, row)))
    print()
