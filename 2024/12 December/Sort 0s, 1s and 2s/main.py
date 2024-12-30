# Link: https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


class Solution:
    def sort012(self, arr):
        size = len(arr)
        idx1 = 0
        idx2 = size - 1
        i = 0

        while i <= idx2:
            if arr[i] == 0:
                arr[i], arr[idx1] = arr[idx1], arr[i]
                idx1 += 1
                i += 1
            elif arr[i] == 2:
                arr[i], arr[idx2] = arr[idx2], arr[i]
                idx2 -= 1
            else:
                i += 1


if __name__ == "__main__":
    object = Solution()
    arr = [0, 1, 2, 0, 1, 2]
    object.sort012(arr)
    print(" ".join(map(str, arr)))

    arr = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
    object.sort012(arr)
    print(" ".join(map(str, arr)))
