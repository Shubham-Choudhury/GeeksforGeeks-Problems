# Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1


class Solution:
    def longSubarrWthSumDivByK(self, arr, n, K):
        map = {}
        cur_sum = 0
        max_len = 0
        test = []
        for i in range(n):
            cur_sum += arr[i]
            mod = cur_sum % K
            test.append([cur_sum, mod])
            if mod == 0:
                max_len = i + 1
            elif mod not in map:
                map[mod] = i
            else:
                max_len = max(max_len, i - map[mod])
        return max_len


if __name__ == "__main__":
    obj = Solution()
    K = 3
    arr = [2, 7, 6, 1, 4, 5]
    N = len(arr)
    print(obj.longSubarrWthSumDivByK(arr, N, K))
    arr = [-2, 2, -5, 12, -11, -1, 7]
    N = len(arr)
    print(obj.longSubarrWthSumDivByK(arr, N, K))
