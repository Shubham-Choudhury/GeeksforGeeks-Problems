# Link: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1


class Solution:
    def search(self, arr, key):
        l, h = 0, len(arr) - 1

        while l <= h:
            mid = l + (h - l) // 2
            if arr[mid] == key:
                return mid
            elif arr[l] <= arr[mid]:
                if arr[l] <= key <= arr[mid]:
                    h = mid - 1
                else:
                    l = mid + 1
            else:
                if arr[mid] <= key <= arr[h]:
                    l = mid + 1
                else:
                    h = mid - 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    A = [5, 6, 7, 8, 9, 10, 1, 2, 3]
    key = 10
    print(obj.search(A, key))

    A = [3, 5, 1, 2]
    key = 6
    print(obj.search(A, key))
