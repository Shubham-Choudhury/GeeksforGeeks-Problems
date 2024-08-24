# Link: https://www.geeksforgeeks.org/problems/number-of-pairs-1587115620/1

from bisect import bisect_right

class Solution:
    def countPairs(self, arr, brr):
        M = len(arr)
        N = len(brr)
        brr.sort()

        countY = [0] * 1001
        for num in brr:
            countY[num] += 1

        def countGreaterThanY(y):
            return N - bisect_right(brr, y)

        result = 0

        for x in arr:
            if x == 0:
                continue
            if x == 1:
                result += countY[0]
                continue
            result += countGreaterThanY(x)
            result += countY[1]
            if x == 2:
                result -= countY[3]
                result -= countY[4]
            if x == 3:
                result += countY[2]

        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 1, 6]
    brr = [1, 5]
    print(obj.countPairs(arr, brr))

    arr = [2, 3, 4, 5]
    brr = [1, 2, 3]
    print(obj.countPairs(arr, brr))
