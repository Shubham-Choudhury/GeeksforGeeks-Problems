# Link: https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1

from typing import List


class Solution:
    def maxTip(self, n: int, x: int, y: int, arr: List[int], brr: List[int]) -> int:
        temp = [[arr[i] - brr[i], arr[i], brr[i]] for i in range(n)]
        temp.sort(key=lambda i: abs(i[0]), reverse=True)
        res = a = b = 0
        for d, i, j in temp:
            if (d >= 0 and a < x) or b == y:
                res, a = res + i, a + 1
            else:
                res, b = res + j, b + 1
        return res


if __name__ == "__main__":
    obj = Solution()
    n = 5
    x = 3
    y = 3
    arr = [1, 2, 3, 4, 5]
    brr = [5, 4, 3, 2, 1]
    print(obj.maxTip(n, x, y, arr, brr))

    n = 8
    x = 4
    y = 4
    arr = [1, 4, 3, 2, 7, 5, 9, 6]
    brr = [1, 2, 3, 6, 5, 4, 9, 8]
    print(obj.maxTip(n, x, y, arr, brr))
