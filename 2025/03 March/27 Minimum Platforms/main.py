# Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1


class Solution:
    def minimumPlatform(self, arr, dep):
        arr.sort()
        dep.sort()
        n = len(arr)
        ans = 1
        count = 1
        i = 1
        j = 0
        while i < n and j < n:
            if arr[i] <= dep[j]:
                count = count + 1
                i = i + 1
            else:
                count = count - 1
                j = j + 1
            if count > ans:
                ans = count
        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]
    print(obj.minimumPlatform(arr, dep))

    arr = [900, 1235, 1100]
    dep = [1000, 1240, 1200]
    print(obj.minimumPlatform(arr, dep))

    arr = [1000, 935, 1100]
    dep = [1200, 1240, 1130]
    print(obj.minimumPlatform(arr, dep))
