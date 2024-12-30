# Link: https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1


class Solution:
    def kthMissing(self, arr, k):
        n = len(arr)
        low, high = 0, n - 1
        while low <= high:
            mid = low + (high - low) // 2
            if arr[mid] - mid - 1 < k:
                low = mid + 1
            else:
                high = mid - 1
        return low + k


if __name__ == "__main__":
    object = Solution()
    arr = [2, 3, 4, 7, 11]
    k = 5
    print(object.kthMissing(arr, k))

    arr = [1, 2, 3]
    k = 2
    print(object.kthMissing(arr, k))

    arr = [3, 5, 9, 10, 11, 12]
    k = 2
    print(object.kthMissing(arr, k))
