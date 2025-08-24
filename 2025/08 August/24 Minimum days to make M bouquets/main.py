# Link: https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1


class Solution:
    def check(self, arr, k, m, days):
        bouquets = 0
        cnt = 0

        for flower in arr:
            if flower <= days:
                cnt += 1
            else:
                bouquets += cnt // k
                cnt = 0

        bouquets += cnt // k

        return bouquets >= m

    def minDaysBloom(self, arr, k, m):
        lo = 0
        hi = max(arr)
        res = -1

        while lo <= hi:
            mid = (lo + hi) // 2

            if self.check(arr, k, m, mid):
                res = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [3, 4, 2, 7, 13, 8, 5]
    m = 3
    k = 2
    result = sol.minDaysBloom(arr, k, m)
    print(f"Minimum days to make {m} bouquets: {result}")

    arr = [5, 5, 5, 5, 10, 5, 5]
    m = 2
    k = 3
    result = sol.minDaysBloom(arr, k, m)
    print(f"Minimum days to make {m} bouquets: {result}")

    arr = [1, 10, 3, 10, 2]
    m = 3
    k = 2
    result = sol.minDaysBloom(arr, k, m)
    print(f"Minimum days to make {m} bouquets: {result}")
