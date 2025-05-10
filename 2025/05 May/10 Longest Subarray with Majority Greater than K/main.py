# Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1
class Solution:
    def longestSubarray(self, arr, k):
        n = len(arr)
        prefIdx = {}
        sum = 0
        res = 0

        for i in range(n):
            sum += 1 if arr[i] > k else -1

            if sum not in prefIdx:
                prefIdx[sum] = i

        if -n in prefIdx:
            return 0
        prefIdx[-n] = n

        for i in range(-n + 1, n + 1):
            if i not in prefIdx:
                prefIdx[i] = prefIdx[i - 1]
            else:
                prefIdx[i] = min(prefIdx[i], prefIdx[i - 1])

        sum = 0
        for i in range(n):
            sum += 1 if arr[i] > k else -1
            if sum > 0:
                res = i + 1
            else:
                res = max(res, i - prefIdx[sum - 1])

        return res


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 1]
    k = 2
    print(obj.longestSubarray(arr, k))

    arr = [6, 5, 3, 4]
    k = 2
    print(obj.longestSubarray(arr, k))
