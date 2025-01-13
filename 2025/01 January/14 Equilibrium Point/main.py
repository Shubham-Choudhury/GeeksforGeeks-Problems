# Link: https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1


class Solution:
    def findEquilibrium(self, arr):
        prefixsum = sum(arr)
        s = 0
        for i in range(len(arr)):
            prefixsum -= arr[i]
            if prefixsum == s:
                return i
            s += arr[i]
        return -1


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 0, 3]
    print(object.findEquilibrium(arr))

    arr = [1, 1, 1, 1]
    print(object.findEquilibrium(arr))

    arr = [-7, 1, 5, 2, -4, 3, 0]
    print(object.findEquilibrium(arr))
