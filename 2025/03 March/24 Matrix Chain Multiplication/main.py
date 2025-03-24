# Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1


class Solution:
    def solver(self, i, j, arr, dp):
        if i == j:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        mini = 1e9

        for k in range(i, j):
            steps = (
                (arr[i - 1] * arr[k] * arr[j])
                + self.solver(i, k, arr, dp)
                + self.solver(k + 1, j, arr, dp)
            )

            if steps < mini:
                mini = steps

        dp[i][j] = mini
        return dp[i][j]

    def matrixMultiplication(self, arr):
        n = len(arr)
        dp = [[-1 for _ in range(n)] for _ in range(n)]
        return self.solver(1, n - 1, arr, dp)


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 1, 3, 4]
    print(obj.matrixMultiplication(arr))

    arr = [1, 2, 3, 4, 3]
    print(obj.matrixMultiplication(arr))

    arr = [3, 4]
    print(obj.matrixMultiplication(arr))
