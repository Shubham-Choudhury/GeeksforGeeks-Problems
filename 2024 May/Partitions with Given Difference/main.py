# Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

from typing import List


class Solution:
    def countPartitions(self, n: int, d: int, arr: List[int]) -> int:
        totsum = sum(arr)
        if totsum - d < 0 or (totsum - d) % 2 != 0:
            return 0
        else:
            k = (totsum - d) // 2
            dp = [[0 for i in range(k + 1)] for i in range(n)]
            if arr[0] == 0:
                dp[0][0] = 2
            else:
                dp[0][0] = 1
            if arr[0] != 0 and arr[0] <= k:
                dp[0][arr[0]] = 1
            for i in range(1, len(dp)):
                for j in range(len(dp[0])):
                    notpick = dp[i - 1][j]
                    pick = 0
                    if arr[i] <= j:
                        pick = dp[i - 1][j - arr[i]]
                    dp[i][j] = (pick + notpick) % (1e9 + 7)
            return int(dp[-1][-1])


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 2, 6, 4]
    n = len(arr)
    d = 3
    print(obj.countPartitions(n, d, arr))

    arr = [1, 1, 1, 1]
    n = len(arr)
    d = 0
    print(obj.countPartitions(n, d, arr))
