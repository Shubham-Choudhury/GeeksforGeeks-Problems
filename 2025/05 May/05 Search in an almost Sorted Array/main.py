# Link: https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1


class Solution:
    def findTarget(self, arr, target):
        n = len(arr)
        s = 0
        e = n - 1
        while s <= e:
            mid = s + (e - s) // 2
            if arr[mid] == target:
                return mid
            if mid - 1 >= s and arr[mid - 1] == target:
                return mid - 1
            if mid + 1 <= e and arr[mid + 1] == target:
                return mid + 1
            if target < arr[mid]:
                e = mid - 1
            else:
                s = mid + 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    arr = [10, 3, 40, 20, 50, 80, 70]
    target = 40
    result = obj.findTarget(arr, target)
    if result != -1:
        print("Element found at index:", result)
    else:
        print("Element not found")

    arr = [10, 3, 40, 20, 50, 80, 70]
    target = 90
    result = obj.findTarget(arr, target)
    if result != -1:
        print("Element found at index:", result)
    else:
        print("Element not found")

    arr = [-20]
    target = -20
    result = obj.findTarget(arr, target)
    if result != -1:
        print("Element found at index:", result)
    else:
        print("Element not found")
