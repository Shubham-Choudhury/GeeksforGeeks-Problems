# Link: https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1


class Solution:
    def pushZerosToEnd(self, arr):
        j = 0
        for i in range(len(arr)):
            if arr[i] != 0:
                arr[i], arr[j] = arr[j], arr[i]
                j += 1


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 0, 4, 3, 0, 5, 0]
    object.pushZerosToEnd(arr)
    print(" ".join(map(str, arr)))

    arr = [10, 20, 30]
    object.pushZerosToEnd(arr)
    print(" ".join(map(str, arr)))

    arr = [0, 0]
    object.pushZerosToEnd(arr)
    print(" ".join(map(str, arr)))
