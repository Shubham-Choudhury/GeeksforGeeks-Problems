# Link: https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1


class Solution:
    def maxDotProduct(self, n, m, a, b):
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(n):
            for j in range(min(m, i + 1)):
                dp[i + 1][j + 1] = max(dp[i][j] + a[i] * b[j], dp[i][j + 1])

        return dp[n][m]


if __name__ == "__main__":
    obj = Solution()
    a = [2, 3, 1, 7, 8]
    b = [3, 6, 7]
    n = len(a)
    m = len(b)
    print(obj.maxDotProduct(n, m, a, b))

    a = [9, 3, 9, 2, 3, 5, 4, 1, 8, 8]
    b = [10, 4, 3, 8]
    n = len(a)
    m = len(b)
    print(obj.maxDotProduct(n, m, a, b))
