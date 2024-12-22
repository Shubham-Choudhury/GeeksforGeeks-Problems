# Link: https://www.geeksforgeeks.org/problems/search-in-a-row-wise-sorted-matrix/1


class Solution:
    def searchRowMatrix(self, mat, x):
        n = len(mat)
        m = len(mat[0])

        for i in range(n):
            if x >= mat[i][0] and x <= mat[i][m - 1]:
                if x in mat[i]:
                    return True
        return False


if __name__ == "__main__":
    object = Solution()
    mat = [[3, 4, 9], [2, 5, 6], [9, 25, 27]]
    x = 9
    print(object.searchRowMatrix(mat, x))
    mat = [[19, 22, 27, 38, 55, 67]]
    x = 56
    print(object.searchRowMatrix(mat, x))
    mat = [[1, 2, 9], [65, 69, 75]]
    x = 91
    print(object.searchRowMatrix(mat, x))
