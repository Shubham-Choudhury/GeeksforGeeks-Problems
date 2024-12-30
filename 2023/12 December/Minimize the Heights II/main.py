# Link: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

# User function Template for python3


class Solution:
    def getMinDiff(self, arr, n, k):
        # code here
        arr.sort()
        result = arr[n - 1] - arr[0]

        for i in range(n - 1):
            max_height = max(arr[i] + k, arr[n - 1] - k)
            min_height = min(arr[0] + k, arr[i + 1] - k)

            if min_height < 0:
                continue
            result = min(result, max_height - min_height)

        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 5, 8, 10]
    n = len(arr)
    k = 2
    print(obj.getMinDiff(arr, n, k))

    arr = [3, 9, 12, 16, 20]
    n = len(arr)
    k = 3
    print(obj.getMinDiff(arr, n, k))
