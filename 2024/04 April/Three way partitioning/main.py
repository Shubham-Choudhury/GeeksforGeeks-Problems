# Link: https://www.geeksforgeeks.org/problems/three-way-partitioning/1


class Solution:
    def threeWayPartition(self, arr, a, b):
        start = 0
        end = len(arr) - 1
        i = 0

        while i <= end:
            if arr[i] < a:
                arr[start], arr[i] = arr[i], arr[start]
                start += 1
                i += 1
            elif arr[i] > b:
                arr[end], arr[i] = arr[i], arr[end]
                end -= 1
            else:
                i += 1


if __name__ == "__main__":
    obj = Solution()
    array = [1, 2, 3, 3, 4]
    a = 1
    b = 2
    obj.threeWayPartition(array, a, b)

    array = [1, 4, 3, 6, 2, 1]
    a = 1
    b = 3
    obj.threeWayPartition(array, a, b)
