# Link: https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1


class Solution:
    def findMin(self, arr):
        mini = float("inf")
        for num in arr:
            mini = min(mini, num)
        return mini


if __name__ == "__main__":
    object = Solution()
    arr = [5, 6, 1, 2, 3, 4]
    print(object.findMin(arr))
    arr = [3, 2, 2, 2]
    print(object.findMin(arr))
    arr = [4, 4, 4]
    print(object.findMin(arr))
