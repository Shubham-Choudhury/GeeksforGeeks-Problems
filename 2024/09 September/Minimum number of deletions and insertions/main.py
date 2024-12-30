# Link: https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1


class Solution:
    def minOperations(self, s1, s2):
        n = len(s1)
        m = len(s2)

        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            for j in range(m + 1):
                if i == 0 or j == 0:
                    dp[i][j] = 0

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        cnt = dp[n][m]
        return n - cnt + m - cnt


if __name__ == "__main__":
    obj = Solution()
    s1 = "heap"
    s2 = "pea"
    print(obj.minOperations(s1, s2))
    s1 = "geeksforgeeks"
    s2 = "geeks"
    print(obj.minOperations(s1, s2))
