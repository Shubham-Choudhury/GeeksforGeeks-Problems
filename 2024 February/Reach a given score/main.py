# Link: https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1


class Solution:
    def count(self, n):
        sum = n
        dp = [0] * (sum + 1)
        dp[0] = 1
        coins = [3, 5, 10]
        for coin in coins:
            for i in range(1, sum + 1):
                dp[i] += dp[i - coin] if i - coin >= 0 else 0
        return dp[sum]


if __name__ == "__main__":
    obj = Solution()
    n = 10
    print(obj.count(n))
    n = 20
    print(obj.count(n))
