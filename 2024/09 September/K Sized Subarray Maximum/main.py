# Link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

from collections import deque


class Solution:
    def max_of_subarrays(self, k, arr):
        result = []
        dq = deque()

        for i in range(len(arr)):
            if dq and dq[0] == i - k:
                dq.popleft()

            while dq and arr[dq[-1]] <= arr[i]:
                dq.pop()

            dq.append(i)

            if i >= k - 1:
                result.append(arr[dq[0]])

        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 1, 4, 5, 2, 3, 6]
    k = 3
    result = obj.max_of_subarrays(k, arr)
    print(" ".join(map(str, result)))

    arr = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
    k = 4
    result = obj.max_of_subarrays(k, arr)
    print(" ".join(map(str, result)))
