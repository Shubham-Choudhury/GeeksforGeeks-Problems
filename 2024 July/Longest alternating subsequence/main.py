# Link: https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

from typing import List


class Solution:
    def alternatingMaxLength(self, arr: List[int]) -> int:
        n = len(arr)
        if n <= 1:
            return n

        up = 1
        down = 1

        for i in range(1, n):
            if arr[i] > arr[i - 1]:
                up = down + 1
            elif arr[i] < arr[i - 1]:
                down = up + 1

        return max(up, down)


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 5, 4]
    print(obj.alternatingMaxLength(arr))

    arr = [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
    print(obj.alternatingMaxLength(arr))
