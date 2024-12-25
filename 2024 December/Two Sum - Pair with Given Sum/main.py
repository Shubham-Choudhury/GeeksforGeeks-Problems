# Link: https://www.geeksforgeeks.org/problems/key-pair5616/1


class Solution:
    def twoSum(self, arr, target):
        mp = {}
        for x in arr:
            if target - x in mp:
                return True
            mp[x] = mp.get(x, 0) + 1
        return False


if __name__ == "__main__":
    object = Solution()
    arr = [1, 4, 45, 6, 10, 8]
    target = 16
    print(object.twoSum(arr, target))

    arr = [1, 2, 4, 3, 6]
    target = 11
    print(object.twoSum(arr, target))
