# Link: https://www.geeksforgeeks.org/problems/need-some-change/1


class Solution:
    def swapElements(self, arr, n):
        for i in range(n - 2):
            arr[i], arr[i + 2] = arr[i + 2], arr[i]


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3]
    n = len(arr)
    obj.swapElements(arr, n)
    print(arr)
    arr = [1, 2, 3, 4, 5]
    n = len(arr)
    obj.swapElements(arr, n)
    print(arr)
