# Link: https://www.geeksforgeeks.org/problems/xoring-and-clearing/1


class Solution:
    def printArr(self, n, arr):
        for x in arr:
            print(x, end=" ")
        print()

    def setToZero(self, n, arr):
        for i in range(n):
            arr[i] = 0

    def xor1ToN(self, n, arr):
        for i in range(n):
            arr[i] = arr[i] ^ i


if __name__ == "__main__":
    obj = Solution()
    arr = [10, 20, 30, 40]
    n = len(arr)
    obj.xor1ToN(n, arr)
    obj.printArr(n, arr)
    obj.setToZero(n, arr)
    obj.printArr(n, arr)
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    n = len(arr)
    obj.xor1ToN(n, arr)
    obj.printArr(n, arr)
    obj.setToZero(n, arr)
    obj.printArr(n, arr)
