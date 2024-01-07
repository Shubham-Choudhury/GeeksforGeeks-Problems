# Link: https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1


class Solution:
    def splitArray(self, arr, N, K):
        l, r = max(arr), sum(arr)
        while l < r:
            mid = (l + r) // 2
            cursum, count = 0, 0
            for num in arr:
                cursum += num
                if cursum > mid:
                    cursum = num
                    count += 1
            if count >= K:
                l = mid + 1
            else:
                r = mid
        return r


if __name__ == "__main__":
    obj = Solution()
    N = 4
    K = 3
    arr = {1, 2, 3, 4}
    print(obj.splitArray(arr, N, K))
