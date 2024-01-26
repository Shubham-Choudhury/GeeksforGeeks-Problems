# Link: https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

import sys


class Solution:
    def matrixChainOrder(self, p, n):
        n = n - 1
        dp = [[sys.maxsize for _ in range(n)] for _ in range(n)]
        ans = [["" for _ in range(n)] for _ in range(n)]

        for len in range(1, n + 1):
            for i in range(n - len + 1):
                if len == 1:
                    dp[i][i] = 0
                    ans[i][i] = chr(ord("A") + i)
                for j in range(i, i + len - 1):
                    cost = (
                        dp[i][j] + p[i] * p[j + 1] * p[i + len] + dp[j + 1][i + len - 1]
                    )
                    if dp[i][i + len - 1] > cost:
                        dp[i][i + len - 1] = cost
                        ans[i][i + len - 1] = (
                            "(" + ans[i][j] + ans[j + 1][i + len - 1] + ")"
                        )

        return ans[0][n - 1]


if __name__ == "__main__":
    obj = Solution()
    p = [1, 2, 3, 4, 5]
    n = len(p)
    print(obj.matrixChainOrder(p, n))
