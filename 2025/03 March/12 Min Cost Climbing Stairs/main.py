# Link: https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1


class Solution:
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        if n == 1:
            return cost[0]
        dp = [0] * n
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(2, n):
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
        return min(dp[n - 2], dp[n - 1])


if __name__ == "__main__":
    obj = Solution()
    cost = [10, 15, 20]
    print(obj.minCostClimbingStairs(cost))

    cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    print(obj.minCostClimbingStairs(cost))
