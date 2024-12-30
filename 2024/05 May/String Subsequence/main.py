# Link: https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1


class Solution:
    def countWays(self, s1: str, s2: str) -> int:
        MOD = int(1e9 + 7)
        n, m = len(s1), len(s2)

        dp = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 1

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD
                else:
                    dp[i][j] = dp[i - 1][j] % MOD

        return dp[n][m]


if __name__ == "__main__":
    obj = Solution()
    s1 = "geeksforgeeks"
    s2 = "gks"
    print(obj.countWays(s1, s2))

    s1 = "problemoftheday"
    s2 = "gks"
    print(obj.countWays(s1, s2))
