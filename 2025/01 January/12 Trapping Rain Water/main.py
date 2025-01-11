# Link: https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1


class Solution:
    def maxWater(self, arr):
        n = len(arr)
        leftMax = [0] * n
        rightMax = [0] * n
        leftMax[0] = 0
        rightMax[n - 1] = 0

        for i in range(1, n):
            leftMax[i] = max(leftMax[i - 1], arr[i - 1])

        for i in range(n - 2, -1, -1):
            rightMax[i] = max(rightMax[i + 1], arr[i + 1])

        store = 0
        for i in range(n):
            ans = min(rightMax[i], leftMax[i])
            if ans > arr[i]:
                store += ans - arr[i]

        return store


if __name__ == "__main__":
    object = Solution()
    arr = [3, 0, 1, 0, 4, 0, 2]
    print(object.maxWater(arr))

    arr = [3, 0, 2, 0, 4]
    print(object.maxWater(arr))

    arr = [1, 2, 3, 4]
    print(object.maxWater(arr))

    arr = [2, 1, 5, 3, 1, 0, 4]
    print(object.maxWater(arr))
