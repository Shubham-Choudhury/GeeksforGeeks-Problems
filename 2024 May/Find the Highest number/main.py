# Link: https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

from typing import List


class Solution:

    def findPeakElement(self, a: List[int]) -> int:
        """
        Time Complexity: O(log(n))
        Space Complexity: O(1)
        """
        n = len(a)
        low, high = 0, n - 1

        while low < high:
            mid = low + (high - low) // 2

            if a[mid] < a[mid + 1]:
                low = mid + 1
            else:
                high = mid

        return a[high]


if __name__ == "__main__":
    obj = Solution()
    a = [1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1]
    print(obj.findPeakElement(a))
    a = [1, 2, 3, 4, 5]
    print(obj.findPeakElement(a))
