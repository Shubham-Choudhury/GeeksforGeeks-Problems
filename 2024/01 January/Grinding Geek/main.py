# Link: https://www.geeksforgeeks.org/problems/grinding-geek/1


class Solution:
    def max_courses(self, n, total, cost):
        dp = [[None] * (total + 1) for _ in range(n)]

        def helper(arr, n, total, pos):
            if pos == n:
                return 0
            if dp[pos][total]:
                return dp[pos][total]
            dp[pos][total] = max(
                helper(arr, n, total, pos + 1),
                (1 + helper(arr, n, total - arr[pos] + int(0.9 * arr[pos]), pos + 1))
                if arr[pos] <= total
                else 0,
            )
            return dp[pos][total]

        return helper(cost, len(cost), total, 0)


if __name__ == "__main__":
    obj = Solution()
    n = 2
    total = 10
    cost = [10, 9]
    print(obj.max_courses(n, total, cost))

    n = 11
    total = 10
    cost = [10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    print(obj.max_courses(n, total, cost))
