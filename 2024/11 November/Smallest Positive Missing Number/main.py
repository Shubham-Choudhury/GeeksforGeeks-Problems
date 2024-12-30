# Link: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1


class Solution:
    def missingNumber(self, arr):
        n = len(arr)
        st = set(arr)

        for i in range(1, 2**31):
            if i not in st:
                return i

        return 1


if __name__ == "__main__":
    object = Solution()
    arr = [2, -3, 4, 1, 1, 7]
    print(object.missingNumber(arr))
    arr = [5, 3, 2, 5, 1]
    print(object.missingNumber(arr))
    arr = [-8, 0, -1, -4, -3]
    print(object.missingNumber(arr))
