# Link: https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1


from typing import List


class Solution:
    def zigZag(self, n: int, arr: List[int]) -> None:
        for i in range(n - 1):
            if i % 2 == 0:
                if arr[i] > arr[i + 1]:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
            else:
                if arr[i] < arr[i + 1]:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
        return arr


if __name__ == "__main__":
    obj = Solution()
    arr = [4, 3, 7, 8, 6, 2, 1]
    n = len(arr)
    print(obj.zigZag(n, arr))

    arr = [1, 4, 3, 2]
    n = len(arr)
    print(obj.zigZag(n, arr))
