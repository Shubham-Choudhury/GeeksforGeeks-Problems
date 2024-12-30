# Link: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1


class Solution:
    def getMinDiff(self, arr, k):
        arr.sort()

        n = len(arr)
        max_diff = arr[-1] - arr[0]

        smallest = arr[0] + k
        largest = arr[-1] - k

        for i in range(1, n):
            min_value = min(smallest, arr[i] - k)
            max_value = max(largest, arr[i - 1] + k)
            if min_value < 0:
                continue
            max_diff = min(max_diff, max_value - min_value)

        return max_diff


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 5, 8, 10]
    k = 2
    print(obj.getMinDiff(arr, k))
    arr = [3, 9, 12, 16, 20]
    k = 3
    print(obj.getMinDiff(arr, k))
