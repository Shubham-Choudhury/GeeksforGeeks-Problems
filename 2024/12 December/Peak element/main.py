# Link: https://www.geeksforgeeks.org/problems/peak-element/1


class Solution:
    def peakElement(self, arr):
        L = 0
        R = len(arr) - 1
        if L == R:
            return 0
        while L <= R:
            M = (L + R) // 2
            if M == 0 and arr[M] > arr[M + 1]:
                return M
            elif M == len(arr) - 1 and arr[M] > arr[M - 1]:
                return M
            elif arr[M] > arr[M + 1] and arr[M] > arr[M - 1]:
                return M
            elif arr[M] > arr[M + 1]:
                R = M - 1
            else:
                L = M + 1
        return -1


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 4, 5, 7, 8, 3]
    print(object.peakElement(arr))

    arr = [10, 20, 15, 2, 23, 90, 80]
    print(object.peakElement(arr))

    arr = [1, 2, 3]
    print(object.peakElement(arr))
