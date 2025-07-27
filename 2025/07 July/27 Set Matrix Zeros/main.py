# Link: https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1


class Solution:
    def setMatrixZeroes(self, mat):
        n = len(mat)
        m = len(mat[0])

        c0 = 1

        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    mat[i][0] = 0

                    if j == 0:
                        c0 = 0
                    else:
                        mat[0][j] = 0

        for i in range(1, n):
            for j in range(1, m):
                if mat[i][0] == 0 or mat[0][j] == 0:
                    mat[i][j] = 0

        if mat[0][0] == 0:
            for j in range(m):
                mat[0][j] = 0

        if c0 == 0:
            for i in range(n):
                mat[i][0] = 0


if __name__ == "__main__":
    sol = Solution()
    mat = [[1, -1, 1], [-1, 0, 1], [1, -1, 1]]
    sol.setMatrixZeroes(mat)
    print("Matrix after setting zeroes:")
    for row in mat:
        print(row)
    print("Done!")

    mat = [[0, 1, 2, 0], [1, 2, 6, 2], [1, 3, 1, 8]]
    sol.setMatrixZeroes(mat)
    print("Matrix after setting zeroes:")
    for row in mat:
        print(row)
    print("Done!")
