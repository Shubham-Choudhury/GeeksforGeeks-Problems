# Link: https://www.geeksforgeeks.org/problems/number-of-coins1824/1


class Solution:
    def minCoins(self, coins, sum):
        INF = float("inf")
        dp = [INF] * (sum + 1)
        dp[0] = 0
        for coin in coins:
            for i in range(coin, sum + 1):
                if dp[i - coin] != INF:
                    dp[i] = min(dp[i], 1 + dp[i - coin])

        return -1 if dp[sum] == INF else dp[sum]


if __name__ == "__main__":
    obj = Solution()
    coins = [25, 10, 5]
    sum = 30
    print(obj.minCoins(coins, sum))

    coins = [9, 6, 5, 1]
    sum = 19
    print(obj.minCoins(coins, sum))

    coins = [5, 1]
    sum = 0
    print(obj.minCoins(coins, sum))

    coins = [4, 6, 2]
    sum = 5
    print(obj.minCoins(coins, sum))
