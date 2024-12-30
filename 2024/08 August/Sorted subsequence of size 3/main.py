# Link: https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1


class Solution:
    def find3Numbers(self, arr):
        n = len(arr)
        leftMin = [-1] * n
        rightMax = [-1] * n

        minIndex = 0
        for i in range(1, n):
            if arr[i] <= arr[minIndex]:
                minIndex = i
            else:
                leftMin[i] = minIndex

        maxIndex = n - 1
        for i in range(n - 2, -1, -1):
            if arr[i] >= arr[maxIndex]:
                maxIndex = i
            else:
                rightMax[i] = maxIndex

        for i in range(n):
            if leftMin[i] != -1 and rightMax[i] != -1:
                return [arr[leftMin[i]], arr[i], arr[rightMax[i]]]

        return []


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 1, 1, 3]
    result = obj.find3Numbers(arr)
    print(" ".join(map(str, result)))

    arr = [1, 1, 3]
    result = obj.find3Numbers(arr)
    print(" ".join(map(str, result)))
