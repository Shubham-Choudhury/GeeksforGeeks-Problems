# Link: https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1

from collections import defaultdict


class Solution:
    def sameOccurrence(self, arr, x, y):
        for i in range(len(arr)):
            if arr[i] == x:
                arr[i] = 1
            elif arr[i] == y:
                arr[i] = -1
            else:
                arr[i] = 0

        m = defaultdict(int)
        sum = 0
        count = 0

        for i in range(len(arr)):
            sum += arr[i]
            if sum == 0:
                count += 1
            count += m[sum]
            m[sum] += 1

        return count


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 1]
    x = 1
    y = 2
    print(obj.sameOccurrence(arr, x, y))
    arr = [1, 2, 1]
    x = 4
    y = 6
    print(obj.sameOccurrence(arr, x, y))
