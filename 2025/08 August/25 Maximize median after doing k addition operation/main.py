# Link: https://www.geeksforgeeks.org/problems/maximize-median-after-doing-k-addition-operation/1


class Solution:
    def isPossible(self, arr, target, k):
        n = len(arr)

        if n % 2 == 1:
            for i in range(n // 2, n):
                if arr[i] < target:
                    k -= target - arr[i]
        else:
            if arr[n // 2] <= target:
                k -= target - arr[n // 2]
                k -= target - arr[n // 2 - 1]
            else:
                k -= 2 * target - (arr[n // 2] + arr[n // 2 - 1])

            for i in range(n // 2 + 1, n):
                if arr[i] < target:
                    k -= target - arr[i]

        return k >= 0

    def maximizeMedian(self, arr, k):
        arr.sort()
        n = len(arr)

        iniMedian = arr[n // 2]
        if n % 2 == 0:
            iniMedian += arr[n // 2 - 1]
            iniMedian //= 2

        low = iniMedian
        high = iniMedian + k
        bestMedian = iniMedian

        while low <= high:
            mid = (low + high) // 2

            if self.isPossible(arr, mid, k):
                bestMedian = mid
                low = mid + 1
            else:
                high = mid - 1

        return bestMedian


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 3, 4, 5]
    k = 3
    result = sol.maximizeMedian(arr, k)
    print("Maximized Median:", result)

    arr = [1, 3, 6, 4, 2]
    k = 10
    result = sol.maximizeMedian(arr, k)
    print("Maximized Median:", result)
