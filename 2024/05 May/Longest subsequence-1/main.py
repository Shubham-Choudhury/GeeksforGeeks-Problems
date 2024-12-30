# Link: https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1


from typing import List


class Solution:
    def longestSubseq(self, n: int, a: List[int]) -> int:
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if abs(a[i] - a[j]) == 1:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)


if __name__ == "__main__":
    obj = Solution()
    arr = [10, 9, 4, 5, 4, 8, 6]
    n = len(arr)
    print(obj.longestSubseq(n, arr))

    arr = {1, 2, 3, 4, 5}
    n = len(arr)
    print(obj.longestSubseq(n, arr))
