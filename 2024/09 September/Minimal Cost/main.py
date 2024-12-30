# Link: https://www.geeksforgeeks.org/problems/minimal-cost/1

import sys


class Solution:
    def minimizeCost(self, k, arr):
        n = len(arr)
        dp = [0] * n

        dp[0] = 0

        for i in range(1, n):
            minSteps = sys.maxsize

            for j in range(1, k + 1):
                if i - j >= 0:
                    jump = dp[i - j] + abs(arr[i] - arr[i - j])
                    minSteps = min(minSteps, jump)

            dp[i] = minSteps

        return dp[n - 1]


if __name__ == "__main__":
    obj = Solution()
    k = 3
    arr = [10, 30, 40, 50, 20]
    print(obj.minimizeCost(k, arr))

    k = 1
    arr = [10, 20, 10]
