# Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-w-in-a-bag1956/1

from typing import List


class Solution:
    def minimumCost(self, n: int, w: int, cost: List[int]) -> int:
        dp = [[float("inf")] * (w + 1) for _ in range(n + 1)]

        for i in range(w + 1):
            dp[0][i] = i * cost[0]

        for i in range(1, n):
            for j in range(w + 1):
                not_pick = dp[i - 1][j]
                pick = float("inf")

                if cost[i] != -1 and (i + 1) <= j:
                    pick = cost[i] + dp[i][j - (i + 1)]

                dp[i][j] = min(pick, not_pick)

        return dp[n - 1][w]


if __name__ == "__main__":
    obj = Solution()
    cost = [20, 10, 4, 50, 100]
    n = len(cost)
    w = 5
    print(obj.minimumCost(n, w, cost))

    cost = [-1, -1, 4, 3, -1]
    n = len(cost)
    w = 5
    print(obj.minimumCost(n, w, cost))
