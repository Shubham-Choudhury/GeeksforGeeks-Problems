# Link: https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1


class Solution:
    def minIncrements(self, arr):
        n = len(arr)
        diff = 0
        arr.sort()
        for i in range(n - 1):
            if arr[i] == arr[i + 1]:
                arr[i + 1] += 1
                diff += 1
            if arr[i] > arr[i + 1]:
                diff += (arr[i] - arr[i + 1]) + 1
                arr[i + 1] = arr[i] + 1
        return diff


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 2]
    print(object.minIncrements(arr))

    arr = [1, 1, 2, 3]
    print(object.minIncrements(arr))

    arr = [5, 4, 3, 2, 1]
    print(object.minIncrements(arr))
