# Link: https://www.geeksforgeeks.org/problems/maximum-profit4657/1


class Solution:
    def maxProfit(self, prices, k):
        n = len(prices)
        if n == 0:
            return 0

        if k >= n // 2:
            total_profit = 0
            for i in range(1, n):
                if prices[i] > prices[i - 1]:
                    total_profit += prices[i] - prices[i - 1]
            return total_profit

        dp = [[0] * n for _ in range(k + 1)]

        for t in range(1, k + 1):
            max_diff = -prices[0]
            for i in range(1, n):
                dp[t][i] = max(dp[t][i - 1], prices[i] + max_diff)
                max_diff = max(max_diff, dp[t - 1][i] - prices[i])

        return dp[k][n - 1]


if __name__ == "__main__":
    obj = Solution()
    prices = [10, 22, 5, 80]
    k = 2
    print(obj.maxProfit(prices, k))

    prices = [20, 580, 420, 900]
    k = 3
    print(obj.maxProfit(prices, k))

    prices = [100, 90, 80, 50, 25]
    k = 1
    print(obj.maxProfit(prices, k))
