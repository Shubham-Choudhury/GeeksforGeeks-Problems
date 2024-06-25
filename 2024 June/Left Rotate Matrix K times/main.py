# Link: https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1


class Solution:
    def rotateMatrix(self, k, mat):
        n, m = len(mat[0]), len(mat)
        k = k % n
        temp = [0] * k
        for j in range(m):
            for i in range(k):
                temp[i] = mat[j][i]
            for i in range(n - k):
                mat[j][i] = mat[j][i + k]
            for i in range(n - k, n):
                mat[j][i] = temp[i - n + k]
        return mat


if __name__ == "__main__":
    obj = Solution()
    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    k = 1
    ans = obj.rotateMatrix(k, mat)
    for row in ans:
        print(" ".join(map(str, row)))

    print()

    mat = [[3, 1, 2], [6, 4, 5], [9, 7, 8]]
    k = 2
    ans = obj.rotateMatrix(k, mat)
    for row in ans:
        print(" ".join(map(str, row)))
