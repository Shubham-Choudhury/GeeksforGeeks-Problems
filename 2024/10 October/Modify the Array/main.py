# Link: https://www.geeksforgeeks.org/problems/ease-the-array0633/1


class Solution:
    def shiftZeroes(self, arr):
        n = len(arr)
        j = 0
        for i in range(n):
            if arr[i] != 0:
                arr[i], arr[j] = arr[j], arr[i]
                j += 1

    def modifyAndRearrangeArr(self, arr):
        for i in range(len(arr) - 1):
            if arr[i] == arr[i + 1] and arr[i] != 0:
                arr[i] *= 2
                arr[i + 1] = 0
        self.shiftZeroes(arr)
        return arr


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 2, 0, 4, 0, 8]
    res = obj.modifyAndRearrangeArr(arr)
    print(" ".join(map(str, res)))

    arr = [0, 2, 2, 2, 0, 6, 6, 0, 0, 8]
    res = obj.modifyAndRearrangeArr(arr)
    print(" ".join(map(str, res)))
