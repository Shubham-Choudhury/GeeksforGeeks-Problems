# Link: https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1

from collections import defaultdict


class Solution:
    def countAtMostK(self, arr, k):
        n = len(arr)
        res = 0

        left, right = 0, 0

        freq = defaultdict(int)
        while right < n:
            freq[arr[right]] += 1

            if freq[arr[right]] == 1:
                k -= 1

            while k < 0:
                freq[arr[left]] -= 1
                if freq[arr[left]] == 0:
                    k += 1
                left += 1

            res += right - left + 1
            right += 1
        return res


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 2, 3]
    k = 2
    result = sol.countAtMostK(arr, k)
    print(f"Number of subarrays with at most {k} distinct integers: {result}")

    arr = [1, 1, 1]
    k = 1
    result = sol.countAtMostK(arr, k)
    print(f"Number of subarrays with at most {k} distinct integers: {result}")

    arr = [1, 2, 1, 1, 3, 3, 4, 2, 1]
    k = 2
    result = sol.countAtMostK(arr, k)
    print(f"Number of subarrays with at most {k} distinct integers: {result}")
