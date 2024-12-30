# Link: https://www.geeksforgeeks.org/problems/pair-sum--120604/1

from typing import List


class Solution:
    def pairsum(self, arr: List[int]) -> int:
        max = arr[0]
        second_max = arr[1]
        if second_max > max:
            max, second_max = second_max, max
        for i in range(2, len(arr)):
            if arr[i] > max:
                second_max = max
                max = arr[i]
            elif arr[i] > second_max:
                second_max = arr[i]
        return max + second_max


if __name__ == "__main__":
    obj = Solution()
    arr = [12, 34, 10, 6, 40]
    print(obj.pairsum(arr))
    arr = [10, 20, 30]
    print(obj.pairsum(arr))
