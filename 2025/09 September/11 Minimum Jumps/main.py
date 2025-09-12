# Link: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


class Solution:
    def minJumps(self, arr):
        n = len(arr)

        if arr[0] == 0:
            return -1

        maxReach = 0
        currReach = 0
        jump = 0

        for i in range(n):
            maxReach = max(maxReach, i + arr[i])
            if maxReach >= n - 1:
                return jump + 1

            if i == currReach:
                if i == maxReach:
                    return -1
                else:
                    jump += 1
                    currReach = maxReach

        return -1


if __name__ == "__main__":
    arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
    solution = Solution()
    result = solution.minJumps(arr)
    print(f"Minimum number of jumps to reach end is: {result}")

    arr = [1, 4, 3, 2, 6, 7]
    result = solution.minJumps(arr)
    print(f"Minimum number of jumps to reach end is: {result}")

    arr = [0, 10, 20]
    result = solution.minJumps(arr)
    print(f"Minimum number of jumps to reach end is: {result}")
