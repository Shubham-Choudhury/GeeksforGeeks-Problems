# Link: https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1


class Solution:
    def ways(self, x, y):
        mod = 1000000007
        dp = [0] * (min(x, y) + 1)
        dp[0] = 1
        for i in range(1, min(x, y) + 1):
            dp[i] = (dp[i - 1] * (x + y - i + 1) * pow(i, mod - 2, mod)) % mod

        return dp[min(x, y)]


if __name__ == "__main__":
    obj = Solution()
    x = 3
    y = 0
    print(obj.ways(x, y))
    x = 3
    y = 6
    print(obj.ways(x, y))
