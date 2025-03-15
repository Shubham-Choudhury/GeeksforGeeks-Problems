# Link: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


class Solution:
    def minJumps(self, arr):
        n = len(arr)
        if n == 1:
            return 0
        if arr[0] == 0:
            return -1

        jumps = 1
        maxReach = arr[0]
        steps = arr[0]

        for i in range(1, n):
            if i == n - 1:
                return jumps

            maxReach = max(maxReach, i + arr[i])
            steps -= 1

            if steps == 0:
                jumps += 1
                if i >= maxReach:
                    return -1
                steps = maxReach - i

        return -1


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
    print(obj.minJumps(arr))

    arr = [1, 4, 3, 2, 6, 7]
    print(obj.minJumps(arr))

    arr = [0, 10, 20]
    print(obj.minJumps(arr))
