# Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1


class Solution:
    def isValid(self, arr, n, m, maxAllowed):
        s = 1
        p = 0
        for i in range(n):
            if arr[i] > maxAllowed:
                return False
            if p + arr[i] <= maxAllowed:
                p += arr[i]
            else:
                s += 1
                p = arr[i]
        return s <= m

    def findPages(self, arr, k):
        n = len(arr)
        if k > n:
            return -1
        total_sum = sum(arr)
        ans = -1
        st = 0
        end = total_sum
        while st <= end:
            mid = st + (end - st) // 2
            if self.isValid(arr, n, k, mid):
                ans = mid
                end = mid - 1
            else:
                st = mid + 1
        return ans


if __name__ == "__main__":
    solution = Solution()
    arr = [12, 34, 67, 90]
    k = 2
    print(solution.findPages(arr, k))

    arr = [15, 17, 20]
    k = 5
    print(solution.findPages(arr, k))

    arr = [22, 23, 67]
    k = 1
    print(solution.findPages(arr, k))
