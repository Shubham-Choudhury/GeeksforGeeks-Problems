# Link: https://www.geeksforgeeks.org/problems/single-number1014/1

from collections import defaultdict


class Solution:
    def getSingle(self, arr):
        f = defaultdict(int)
        for i in arr:
            f[i] += 1
        for key, value in f.items():
            if value % 2 == 1:
                return key
        return -1


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 1, 2, 2, 2]
    print(obj.getSingle(arr))

    arr = [8, 8, 7, 7, 6, 6, 1]
    print(obj.getSingle(arr))
