# Link: https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1


class Solution:
    def longestSubarray(self, arr, x):
        n = len(arr)
        min_queue = []
        max_queue = []
        left = 0
        res, left_idx, right_idx = 0, 0, 0

        for right in range(n):
            v = arr[right]

            while min_queue and arr[min_queue[-1]] > v:
                min_queue.pop()
            min_queue.append(right)

            while max_queue and arr[max_queue[-1]] < v:
                max_queue.pop()
            max_queue.append(right)

            while arr[max_queue[0]] - arr[min_queue[0]] > x:
                left += 1
                if min_queue[0] < left:
                    min_queue.pop(0)
                if max_queue[0] < left:
                    max_queue.pop(0)

            if right - left + 1 > res:
                res = right - left + 1
                left_idx = left
                right_idx = right + 1

        return arr[left_idx:right_idx]


if __name__ == "__main__":
    object = Solution()
    arr = [8, 4, 2, 6, 7]
    x = 4
    result = object.longestSubarray(arr, x)
    print(" ".join(map(str, result)))

    arr = [15, 10, 1, 2, 4, 7, 2]
    x = 5
    result = object.longestSubarray(arr, x)
    print(" ".join(map(str, result)))
