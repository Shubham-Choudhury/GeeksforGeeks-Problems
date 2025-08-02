# Link: https://www.geeksforgeeks.org/problems/2-d-difference-array/1


class Solution:
    def applyDiff2D(self, mat, opr):
        n = len(mat)
        m = len(mat[0])

        diff = [[0] * m for _ in range(n)]

        for q in opr:
            v, r1, c1, r2, c2 = q

            diff[r1][c1] += v

            if c2 + 1 < m:
                diff[r1][c2 + 1] -= v

            if r2 + 1 < n:
                diff[r2 + 1][c1] -= v

            if r2 + 1 < n and c2 + 1 < m:
                diff[r2 + 1][c2 + 1] += v

        for i in range(n):
            for j in range(1, m):
                diff[i][j] += diff[i][j - 1]

        for j in range(m):
            for i in range(1, n):
                diff[i][j] += diff[i - 1][j]

        for i in range(n):
            for j in range(m):
                mat[i][j] += diff[i][j]

        return mat


if __name__ == "__main__":
    sol = Solution()
    mat = [[1, 2, 3], [1, 1, 0], [4, -2, 2]]
    opr = [[2, 0, 0, 1, 1], [-1, 1, 0, 2, 2]]
    result = sol.applyDiff2D(mat, opr)
    for row in result:
        print(row)
