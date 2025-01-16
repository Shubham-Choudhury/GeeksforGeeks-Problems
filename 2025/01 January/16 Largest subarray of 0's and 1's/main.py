# Link: https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1


class Solution:
    def maxLen(self, arr):
        max_len = 0
        prefix_sum_map = {}
        presum = 0

        for i in range(len(arr)):
            presum += -1 if arr[i] == 0 else 1
            if presum == 0:
                max_len = i + 1
            if presum in prefix_sum_map:
                max_len = max(max_len, i - prefix_sum_map[presum])
            else:
                prefix_sum_map[presum] = i

        return max_len


if __name__ == "__main__":
    object = Solution()
    arr = [1, 0, 1, 1, 1, 0, 0]
    print(object.maxLen(arr))

    arr = [0, 0, 1, 1, 0]
    print(object.maxLen(arr))

    arr = [0]
    print(object.maxLen(arr))
