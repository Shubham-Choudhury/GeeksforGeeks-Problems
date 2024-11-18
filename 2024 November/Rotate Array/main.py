# Link: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1


class Solution:
    def rotateArr(self, arr, d):
        n = len(arr)
        d = d % n
        arr.reverse()
        arr[: n - d] = reversed(arr[: n - d])
        arr[n - d :] = reversed(arr[n - d :])


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 3, 4, 5]
    d = 2
    object.rotateArr(arr, d)
    print(" ".join(map(str, arr)))

    arr = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
    d = 3
    object.rotateArr(arr, d)
    print(" ".join(map(str, arr)))

    arr = [7, 3, 9, 1]
    d = 9
    object.rotateArr(arr, d)
    print(" ".join(map(str, arr)))
