# Link: https://www.geeksforgeeks.org/problems/dice-throw5349/1


class Solution:
    def noOfWays(self, m, n, x):
        dp = [0] * (x + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            for j in range(x, 0, -1):
                dp[j] = 0
                for k in range(1, m + 1):
                    if j - k >= 0:
                        dp[j] += dp[j - k]

            dp[0] = 0
        return dp[x]


if __name__ == "__main__":
    obj = Solution()
    m = 6
    n = 3
    x = 12
    print(obj.noOfWays(m, n, x))

    m = 2
    n = 3
    x = 6
    print(obj.noOfWays(m, n, x))
