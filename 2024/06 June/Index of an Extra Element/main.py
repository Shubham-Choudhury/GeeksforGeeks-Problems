# Link: https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1


class Solution:
    def findExtra(self, n, a, b):
        low = 0
        high = n - 2
        index = n - 1
        while low <= high:
            mid = (low + high) // 2
            if a[mid] == b[mid]:
                low = mid + 1
            else:
                index = mid
                high = mid - 1

        return index


if __name__ == "__main__":
    obj = Solution()
    a = [2, 4, 6, 8, 9, 10, 12]
    b = [2, 4, 6, 8, 10, 12]
    n = len(a)
    print(obj.findExtra(n, a, b))

    a = [3, 5, 7, 8, 11, 13]
    b = [3, 5, 7, 11, 13]
    n = len(a)
    print(obj.findExtra(n, a, b))
