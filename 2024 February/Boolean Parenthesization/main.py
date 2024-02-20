# Link: https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1


class Solution:
    def countWays(self, n, s):
        dp = [[[0, 0] for i in range(n)] for j in range(n)]
        for i in range(0, n, 2):
            if s[i] == "T":
                dp[i][i][1] = 1
            else:
                dp[i][i][0] = 1
        for l in range(3, n + 1, 2):
            for i in range(0, n - l + 1, 2):
                j = i + l - 1
                t = (l - 1) // 2
                for k in range(1, t + 1):
                    k2 = 2 * k
                    if s[i + k2 - 1] == "&":
                        dp[i][j][1] += dp[i][i + k2 - 2][1] * dp[i + k2][j][1]
                        dp[i][j][0] += (
                            dp[i][i + k2 - 2][1] * dp[i + k2][j][0]
                            + dp[i][i + k2 - 2][0] * dp[i + k2][j][1]
                            + dp[i][i + k2 - 2][0] * dp[i + k2][j][0]
                        )
                    elif s[i + k2 - 1] == "|":
                        dp[i][j][0] += dp[i][i + k2 - 2][0] * dp[i + k2][j][0]
                        dp[i][j][1] += (
                            dp[i][i + k2 - 2][0] * dp[i + k2][j][1]
                            + dp[i][i + k2 - 2][1] * dp[i + k2][j][0]
                            + dp[i][i + k2 - 2][1] * dp[i + k2][j][1]
                        )
                    else:
                        dp[i][j][0] += (
                            dp[i][i + k2 - 2][0] * dp[i + k2][j][0]
                            + dp[i][i + k2 - 2][1] * dp[i + k2][j][1]
                        )
                        dp[i][j][1] += (
                            dp[i][i + k2 - 2][1] * dp[i + k2][j][0]
                            + dp[i][i + k2 - 2][0] * dp[i + k2][j][1]
                        )
        return dp[0][n - 1][1] % 1003


if __name__ == "__main__":
    obj = Solution()
    n = 7
    s = "T|T&F^T"
    print(obj.countWays(n, s))
    n = 5
    s = "T^F|F"
    print(obj.countWays(n, s))
