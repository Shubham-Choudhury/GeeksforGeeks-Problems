# Link: https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1

from typing import List


class Solution:
    def findClosest(self, n: int, k: int, arr: List[int]) -> int:
        import bisect

        ix = bisect.bisect(arr, k)
        if ix == n:
            return arr[-1]
        if arr[ix] == k:
            return k
        return arr[ix - 1] if k - arr[ix - 1] < arr[ix] - k else arr[ix]


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 3, 6, 7]
    n = len(arr)
    k = 4
    print(obj.findClosest(n, k, arr))

    arr = [1, 2, 3, 5, 6, 8, 9]
    n = len(arr)
    k = 4
    print(obj.findClosest(n, k, arr))
