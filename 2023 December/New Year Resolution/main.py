# Link: https://www.geeksforgeeks.org/problems/good-by-2023/1

from typing import List


class Solution:
    def isPossible(self, N : int, coins : List[int]) -> bool:
        s = sum(coins)
        if s == 2024:
            return True
        dp = [True] + [False]*s
        
        for c in coins:
            for i in range(s, c-1, -1):
                dp[i] = dp[i] or dp[i-c]

        return any(dp[i] for i in range(20, s+1, 20)) or any(dp[i] for i in range(24, s+1, 24))


if __name__ == "__main__":
    obj = Solution()
    coins = [5, 8, 9, 10, 14, 2, 3, 5]
    n = len(coins)
    print(obj.isPossible(n, coins))
