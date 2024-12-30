# Link: https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1


class Solution:
    def getMinDiff(self, k, arr):
        arr.sort()
        n = len(arr)
        minV = arr[0]
        maxV = arr[n - 1]
        ans = maxV - minV
        for i in range(1, n):
            minV = min(arr[0] + k, arr[i] - k)
            maxV = max(arr[n - 1] - k, arr[i - 1] + k)
            ans = min(ans, maxV - minV)
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [1, 5, 8, 10]
    k = 2
    print(object.getMinDiff(k, arr))

    arr = [3, 9, 12, 16, 20]
    k = 3
    print(object.getMinDiff(k, arr))
