# Link: https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1


class Solution:
    def balanceSums(self, mat):
        n = len(mat)
        res = 0
        maxSum = 0

        for i in range(n):
            row_total = sum(mat[i])
            maxSum = max(row_total, maxSum)

        for j in range(n):
            col_total = sum(mat[i][j] for i in range(n))
            maxSum = max(col_total, maxSum)

        for i in range(n):
            row_total = sum(mat[i])
            res += maxSum - row_total

        return res


if __name__ == "__main__":
    sol = Solution()
    mat = [[1, 2], [3, 4]]
    result = sol.balanceSums(mat)
    print(f"Minimum operations to make the matrix beautiful: {result}")

    mat = [[1, 2, 3], [4, 2, 3], [3, 2, 1]]
    result = sol.balanceSums(mat)
    print(f"Minimum operations to make the matrix beautiful: {result}")
