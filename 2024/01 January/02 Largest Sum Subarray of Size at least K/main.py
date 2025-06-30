# Link: https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1


class Solution:
    def maxSumWithK(self, a, n, k):
        maxend = 0
        s = 0
        res = float("-inf")
        for i in range(n):
            s += a[i]
            if i >= k:
                s -= a[i - k]
                maxend = max(0, a[i - k], a[i - k] + maxend)
            if i >= k - 1:
                res = max(res, s + maxend)
        return res


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSumWithK([1, 2, 3, -10, -3], 5, 4))
