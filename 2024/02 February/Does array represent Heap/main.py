# Link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1


class Solution:
    def isMaxHeap(self, arr, n):
        for i in range(((n - 2) // 2) + 1):
            if arr[2 * i + 1] > arr[i]:
                return False

            if 2 * i + 2 < n and arr[2 * i + 2] > arr[i]:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    arr = [9, 15, 10, 7, 12, 11]
    n = len(arr)
    print(obj.isMaxHeap(arr, n))
    arr = [90, 15, 10, 7, 12, 2]
    n = len(arr)
    print(obj.isMaxHeap(arr, n))
