# Link: https://www.geeksforgeeks.org/problems/find-unique-number/1


class Solution:
    def findUnique(self, arr):
        x = 0
        for e in arr:
            x = x ^ e
        return x


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 1, 5, 5]
    print(obj.findUnique(arr))

    arr = [2, 30, 2, 15, 20, 30, 15]
    print(obj.findUnique(arr))
