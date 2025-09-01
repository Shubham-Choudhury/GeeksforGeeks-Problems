# Link: https://www.geeksforgeeks.org/problems/container-with-most-water0535/1


class Solution:

    def maxWater(self, arr):
        left = 0
        right = len(arr) - 1
        res = 0
        while left < right:
            water = min(arr[left], arr[right]) * (right - left)
            res = max(res, water)

            if arr[left] < arr[right]:
                left += 1
            else:
                right -= 1

        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 5, 4, 3]
    result = sol.maxWater(arr)
    print("Maximum water that can be contained is:", result)

    arr = [3, 1, 2, 4, 5]
    result = sol.maxWater(arr)
    print("Maximum water that can be contained is:", result)

    arr = [2, 1, 8, 6, 4, 6, 5, 5]
    result = sol.maxWater(arr)
    print("Maximum water that can be contained is:", result)
