# Link: https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1


class Solution:
    def rotateby90(self, mat):
        n = len(mat)
        for i in range(n - 1):
            for j in range(i + 1, n):
                mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
        mat.reverse()


if __name__ == "__main__":
    object = Solution()
    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    object.rotateby90(mat)
    for row in mat:
        print(" ".join(map(str, row)))

    mat = [[1, 2], [3, 4]]
    object.rotateby90(mat)
    for row in mat:
        print(" ".join(map(str, row)))
