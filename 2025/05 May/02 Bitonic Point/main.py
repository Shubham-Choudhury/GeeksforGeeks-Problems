# Link: https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1


class Solution:
    def findMaximum(self, arr):
        ans = -1
        n = len(arr)
        low = 0
        high = n - 1
        while low <= high:
            mid = low + (high - low) // 2
            if (mid == 0 or arr[mid - 1] <= arr[mid]) and (
                mid == n - 1 or arr[mid] >= arr[mid + 1]
            ):
                ans = arr[mid]
            if mid > 0 and arr[mid - 1] > arr[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return ans


if __name__ == "__main__":
    s = Solution()
    arr = [1, 2, 4, 5, 7, 8, 3]
    print(s.findMaximum(arr))

    arr = [10, 20, 30, 40, 50]
    print(s.findMaximum(arr))

    arr = [120, 100, 80, 20, 0]
    print(s.findMaximum(arr))
