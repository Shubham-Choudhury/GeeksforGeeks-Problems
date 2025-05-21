# Link: https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1


class Solution:
    def count(self, val, m, n):
        cnt = 0
        for i in range(1, m + 1):
            cnt += min(val // i, n)
        return cnt

    def kthSmallest(self, m, n, k):
        l, h = 1, m * n
        while l < h:
            mid = (l + h) // 2
            if self.count(mid, m, n) < k:
                l = mid + 1
            else:
                h = mid

        return l


if __name__ == "__main__":
    obj = Solution()
    m = 3
    n = 3
    k = 5
    print(obj.kthSmallest(m, n, k))

    m = 2
    n = 3
    k = 6
    print(obj.kthSmallest(m, n, k))
