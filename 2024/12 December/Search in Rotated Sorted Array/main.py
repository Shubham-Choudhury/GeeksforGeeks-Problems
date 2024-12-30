# Link: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1


class Solution:
    def search(self, arr, key):
        n = len(arr)
        low = 0
        high = n - 1
        while low <= high:
            mid = (low + high) // 2
            if arr[mid] == key:
                return mid
            if arr[low] <= arr[mid]:
                if key >= arr[low] and key < arr[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if key > arr[mid] and key <= arr[high]:
                    low = mid + 1
                else:
                    high = mid - 1
        return -1


if __name__ == "__main__":
    object = Solution()
    arr = [5, 6, 7, 8, 9, 10, 1, 2, 3]
    key = 3
    print(object.search(arr, key))

    arr = [3, 5, 1, 2]
    key = 6
    print(object.search(arr, key))

    arr = [33, 42, 72, 99]
    key = 42
    print(object.search(arr, key))
