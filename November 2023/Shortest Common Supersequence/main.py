# Link: https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1


class Solution:
    def shortestCommonSupersequence(self, X, Y, m, n):
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        length = 0
        for i in range(m + 1):
            dp[i][0] = 0
        for i in range(n + 1):
            dp[0][i] = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if X[i - 1] == Y[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
        length = dp[m][n]
        l1 = m - length
        l2 = n - length
        return length + l1 + l2


if __name__ == "__main__":
    obj = Solution()
    print(obj.shortestCommonSupersequence("AGGTAB", "GXTXAYB", 6, 7))
