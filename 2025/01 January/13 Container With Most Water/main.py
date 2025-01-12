# Link: https://www.geeksforgeeks.org/problems/container-with-most-water0535/1


class Solution:
    def maxWater(self, arr):
        n = len(arr)
        i, j = 0, n - 1
        maxi = 0
        while i < j:
            maxi = max(maxi, min(arr[i], arr[j]) * (j - i))

            if arr[i] <= arr[j]:
                i += 1
            else:
                j -= 1
        return maxi


if __name__ == "__main__":
    object = Solution()
    arr = [1, 5, 4, 3]
    print(object.maxWater(arr))

    arr = [3, 1, 2, 4, 5]
    print(object.maxWater(arr))

    arr = [2, 1, 8, 6, 4, 6, 5, 5]
    print(object.maxWater(arr))
