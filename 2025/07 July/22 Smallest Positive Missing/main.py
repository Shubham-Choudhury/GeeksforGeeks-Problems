# Link: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1


class Solution:
    def missingNumber(self, arr):
        n = len(arr)
        for i in range(n):
            while 1 <= arr[i] <= n and arr[i] != arr[arr[i] - 1]:
                temp = arr[i]
                arr[i] = arr[arr[i] - 1]
                arr[temp - 1] = temp

        for i in range(1, n + 1):
            if i != arr[i - 1]:
                return i

        return n + 1


if __name__ == "__main__":
    sol = Solution()
    arr = [2, -3, 4, 1, 1, 7]
    result = sol.missingNumber(arr)
    print(f"Missing number in {arr} is: {result}")

    arr = [5, 3, 2, 5, 1]
    result = sol.missingNumber(arr)
    print(f"Missing number in {arr} is: {result}")

    arr = [-8, 0, -1, -4, -3]
    result = sol.missingNumber(arr)
    print(f"Missing number in {arr} is: {result}")
