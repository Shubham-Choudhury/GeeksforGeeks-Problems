# Link: https://www.geeksforgeeks.org/problems/ncr1019/1

import math


class Solution:
    def nCr(self, n, r):
        if r > n:
            return 0
        if r == 0 or n == r:
            return 1

        res = 0

        for i in range(r):
            res += math.log(n - i) - math.log(i + 1)

        return round(math.exp(res))


if __name__ == "__main__":
    obj = Solution()
    n = 5
    r = 2
    print(obj.nCr(n, r))
    n = 2
    r = 4
    print(obj.nCr(n, r))
    n = 5
    r = 0
    print(obj.nCr(n, r))
