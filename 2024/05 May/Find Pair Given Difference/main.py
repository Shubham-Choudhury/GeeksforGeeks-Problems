# Link: https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

from typing import List


class Solution:
    def findPair(self, n: int, x: int, arr: List[int]) -> int:
        num_set = set(arr)
        for num in num_set:
            if num + x in num_set or num - x in num_set:
                return 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 20, 3, 2, 5, 80]
    n = len(arr)
    x = 78
    print(obj.findPair(n, x, arr))  # 1

    arr = [90, 70, 20, 80, 50]
    n = len(arr)
    x = 45
    print(obj.findPair(n, x, arr))  # -1
