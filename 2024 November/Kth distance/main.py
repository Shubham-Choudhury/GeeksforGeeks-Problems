# Link: https://www.geeksforgeeks.org/problems/kth-distance3757/1


class Solution:
    def checkDuplicatesWithinK(self, arr, k):
        mp = {}
        for i in range(len(arr)):
            if arr[i] in mp and i - mp[arr[i]] <= k:
                return True
            mp[arr[i]] = i
        return False


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 3, 4, 1, 2, 3, 4]
    k = 3
    print(object.checkDuplicatesWithinK(arr, k))
    arr = [1, 2, 3, 1, 4, 5]
    k = 3
    print(object.checkDuplicatesWithinK(arr, k))
