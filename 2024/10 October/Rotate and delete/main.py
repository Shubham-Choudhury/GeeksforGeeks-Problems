# Link: https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1

import math


class Solution:
    def rotatedelete(self, arr):
        n = len(arr)
        if n == 1:
            return arr[0]
        if n % 2 == 1:
            return arr[math.floor((n - 3) / 4) + 2]
        else:
            return arr[math.floor((n - 2) / 4) + 1]


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 5, 6]
    print(obj.rotatedelete(arr))

    arr = [1, 2, 3, 4]
    print(obj.rotatedelete(arr))
