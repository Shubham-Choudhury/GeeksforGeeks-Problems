# Link: https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

from typing import List

class Solution:
    def maxProfit(self, n: int, price: List[int]) -> int:
        dp = [[[0 for _ in range(3)] for i in range(2)] for j in range(n + 1)]

        for index in range(n - 1, -1, -1):
            for bs in range(1, -1, -1):
                for limit in range(2, 0, -1):
                    if bs:
                        buy = -price[index] + dp[index + 1][0][limit]
                        skip = 0 + dp[index + 1][1][limit]
                        dp[index][bs][limit] = max(buy, skip)
                    else:
                        sell = price[index] + dp[index + 1][1][limit - 1]
                        skip = 0 + dp[index + 1][0][limit]
                        dp[index][bs][limit] = max(sell, skip)
        return dp[0][1][2]


if __name__ == "__main__":
    obj = Solution()
    prices = [10, 22, 5, 75, 65, 80]
    n = len(prices)
    print(obj.maxProfit(n, prices))
    prices = [2, 30, 15, 10, 8, 25, 80]
    n = len(prices)
    print(obj.maxProfit(n, prices))
