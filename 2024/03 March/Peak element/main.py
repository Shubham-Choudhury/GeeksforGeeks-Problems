# Link: https://www.geeksforgeeks.org/problems/peak-element/1


class Solution:
    def peakElement(self, arr, n):
        if len(arr) == 0:
            return 0
        left, right = 0, len(arr) - 1
        while left < right:
            mid = (left + right) // 2
            if arr[mid] < arr[mid + 1]:
                left = mid + 1
            else:
                right = mid
        return left


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3]
    n = len(arr)
    print(obj.peakElement(arr, n))
