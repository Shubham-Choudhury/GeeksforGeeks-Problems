# Link: https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1


class Solution:
    def setMatrixZeroes(self, mat):
        n = len(mat)
        m = len(mat[0])
        col0 = 1
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    mat[i][0] = 0
                    if j != 0:
                        mat[0][j] = 0
                    else:
                        col0 = 0
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][j] != 0:
                    if mat[i][0] == 0 or mat[0][j] == 0:
                        mat[i][j] = 0
        if mat[0][0] == 0:
            for j in range(m):
                mat[0][j] = 0
        if col0 == 0:
            for i in range(n):
                mat[i][0] = 0


if __name__ == "__main__":
    object = Solution()
    mat = [[1, -1, 1], [-1, 0, 1], [1, -1, 1]]
    object.setMatrixZeroes(mat)
    for row in mat:
        print(" ".join(map(str, row)))
    print()

    mat = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    object.setMatrixZeroes(mat)
    for row in mat:
        print(" ".join(map(str, row)))
    print()
