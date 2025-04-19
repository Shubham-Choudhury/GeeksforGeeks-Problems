# Link: https://www.geeksforgeeks.org/problems/find-repetitive-element-from-1-to-n-1/1


class Solution:
    def findDuplicate(self, arr):
        return sum(arr) - sum(set(arr))


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 3, 2, 3, 4]
    print(obj.findDuplicate(arr))
    arr = [1, 5, 1, 2, 3, 4]
    print(obj.findDuplicate(arr))
    arr = [1, 1]
    print(obj.findDuplicate(arr))
