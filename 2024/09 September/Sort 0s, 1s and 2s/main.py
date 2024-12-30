# Link: https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


class Solution:
    def sort012(self, arr):
        n = len(arr)
        low, mid, high = 0, 0, n - 1
        while mid <= high:
            if arr[mid] == 0:
                arr[low], arr[mid] = arr[mid], arr[low]
                mid += 1
                low += 1
            elif arr[mid] == 1:
                mid += 1
            else:
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1


if __name__ == "__main__":
    obj = Solution()
    arr = [0, 2, 1, 2, 0]
    obj.sort012(arr)
    print(" ".join(map(str, arr)))

    arr = [0, 1, 0]
    obj.sort012(arr)
    print(" ".join(map(str, arr)))
