# Link: https://www.geeksforgeeks.org/problems/coin-piles5152/1

import bisect


class Solution:
    def minimumCoins(self, arr, k):
        arr.sort()
        n = len(arr)

        prefix = [0] * n
        prefix[0] = arr[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + arr[i]

        ans = float("inf")
        prev = 0

        for i in range(n):
            if i > 0 and arr[i] == arr[i - 1]:
                continue

            if i > 0:
                prev = prefix[i - 1]

            target = arr[i] + k
            pos = bisect.bisect_right(arr, target, i)
            totalToRemove = prev
            if pos < n:
                totalToRemove += (
                    prefix[n - 1] - prefix[pos - 1] - (n - pos) * (arr[i] + k)
                )

            ans = min(ans, totalToRemove)

        return ans


if __name__ == "__main__":
    sol = Solution()
    arr = [2, 2, 2, 2]
    k = 0
    print(sol.minimumCoins(arr, k))

    arr = [1, 5, 1, 2, 5, 1]
    k = 3
    print(sol.minimumCoins(arr, k))
