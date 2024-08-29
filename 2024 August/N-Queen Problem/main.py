# Link: https://www.geeksforgeeks.org/problems/n-queen-problem0315/1


class Solution:
    def isValid(self, i, j, matrix):
        x, y = i, j
        n = len(matrix)
        for j in range(n):
            if matrix[x][j] != 0:
                return False
        for i in range(n):
            if matrix[i][y] != 0:
                return False
        for i, j in zip(range(x, n), range(y, n)):
            if matrix[i][j] != 0:
                return False
        for i, j in zip(range(x, -1, -1), range(y, -1, -1)):
            if matrix[i][j] != 0:
                return False
        for i, j in zip(range(x, n), range(y, -1, -1)):
            if matrix[i][j] != 0:
                return False
        for i, j in zip(range(x, -1, -1), range(y, n)):
            if matrix[i][j] != 0:
                return False
        return True

    def solve(self, j, matrix, temp, ans):
        n = len(matrix)
        if j == n:
            ans.append(temp.copy())
            return
        for i in range(n):
            if self.isValid(i, j, matrix):
                temp.append(i + 1)
                matrix[i][j] = i + 1
                self.solve(j + 1, matrix, temp, ans)
                matrix[i][j] = 0
                temp.pop()

    def nQueen(self, n):
        ans = []
        temp = []
        matrix = [[0] * n for _ in range(n)]
        self.solve(0, matrix, temp, ans)
        return ans


if __name__ == "__main__":
    obj = Solution()
    n = 1
    ans = obj.nQueen(n)
    for row in ans:
        print(" ".join(map(str, row)))
    print()

    n = 4
    ans = obj.nQueen(n)
    for row in ans:
        print(" ".join(map(str, row)))
    print()
