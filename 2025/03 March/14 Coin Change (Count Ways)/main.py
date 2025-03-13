# Link: https://www.geeksforgeeks.org/problems/coin-change2448/1


class Solution:
    def solve(self, i, coins, sum, curr_sum, dp):
        if curr_sum > sum:
            return 0
        if i == len(coins):
            return 1 if curr_sum == sum else 0
        if dp[i][curr_sum] != -1:
            return dp[i][curr_sum]

        take = self.solve(i, coins, sum, curr_sum + coins[i], dp)
        not_take = self.solve(i + 1, coins, sum, curr_sum, dp)

        dp[i][curr_sum] = take + not_take
        return dp[i][curr_sum]

    def count(self, coins, sum):
        n = len(coins)
        dp = [[-1] * (sum + 1) for _ in range(n)]
        return self.solve(0, coins, sum, 0, dp)


if __name__ == "__main__":
    obj = Solution()
    coins = [1, 2, 3]
    sum = 4
    print(obj.count(coins, sum))

    coins = [2, 5, 3, 6]
    sum = 10
    print(obj.count(coins, sum))

    coins = [5, 10]
    sum = 3
    print(obj.count(coins, sum))
