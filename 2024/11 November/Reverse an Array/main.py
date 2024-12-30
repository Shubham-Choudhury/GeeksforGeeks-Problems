# Link: https://www.geeksforgeeks.org/problems/reverse-an-array/1


class Solution:
    def reverseArray(self, arr):
        n = len(arr)
        for i in range(n // 2):
            arr[i], arr[n - i - 1] = arr[n - i - 1], arr[i]


if __name__ == "__main__":
    object = Solution()
    arr = [1, 4, 3, 2, 6, 5]
    object.reverseArray(arr)
    print(" ".join(map(str, arr)))

    arr = [4, 5, 2]
    object.reverseArray(arr)
    print(" ".join(map(str, arr)))

    arr = [1]
    object.reverseArray(arr)
    print(" ".join(map(str, arr)))
