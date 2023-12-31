# Link: https://www.geeksforgeeks.org/problems/good-by-2023/1

from typing import List


class Solution:
    def isPossible(self, n: int, arr: List[int]) -> bool:
        dp = [[0] * (n + 1) for _ in range(2025)]
        for i in range(n + 1):
            dp[0][i] = True
        for s in range(1, 2025):
            for i in range(n):
                dp[s][i + 1] = dp[s][i]
                if s >= arr[i]:
                    dp[s][i + 1] = dp[s][i + 1] or dp[s - arr[i]][i]
                if dp[s][i + 1] and (s % 20 == 0 or s % 24 == 0 or s == 2024):
                    return True

        return False


if __name__ == "__main__":
    obj = Solution()
    coins = [5, 8, 9, 10, 14, 2, 3, 5]
    n = len(coins)
    print(obj.isPossible(n, coins))
