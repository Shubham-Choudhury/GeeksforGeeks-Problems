# Link: https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1


class Solution:
    def maxDistance(self, arr):
        mp = {}
        result = 0

        n = len(arr)
        for i in range(n):
            if arr[i] in mp:
                result = max(result, i - mp[arr[i]])
            else:
                mp[arr[i]] = i

        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 1, 2, 2, 2, 1]
    print(obj.maxDistance(arr))

    arr = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]
    print(obj.maxDistance(arr))
