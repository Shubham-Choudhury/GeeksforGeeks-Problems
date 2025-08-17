# Link: https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1


class Solution:
    def rearrange(self, arr, x):
        arr.sort(key=lambda a: abs(a - x))


if __name__ == "__main__":
    sol = Solution()
    arr = [10, 5, 3, 9, 2]
    x = 7
    sol.rearrange(arr, x)
    print(arr)

    arr = [1, 2, 3, 4, 5]
    x = 6
    sol.rearrange(arr, x)
    print(arr)
