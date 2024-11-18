# Link: https://www.geeksforgeeks.org/problems/next-permutation5226/1


class Solution:
    def nextPermutation(self, arr):
        n = len(arr)
        i = n - 2
        while i >= 0 and arr[i] >= arr[i + 1]:
            i -= 1

        if i >= 0:

            j = n - 1
            while arr[j] <= arr[i]:
                j -= 1

            arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1 :] = reversed(arr[i + 1 :])
        return arr


if __name__ == "__main__":
    object = Solution()
    arr = [2, 4, 1, 7, 5, 0]
    object.nextPermutation(arr)
    print(" ".join(map(str, arr)))

    arr = [3, 2, 1]
    object.nextPermutation(arr)
    print(" ".join(map(str, arr)))

    arr = [3, 4, 2, 5, 1]
    object.nextPermutation(arr)
    print(" ".join(map(str, arr)))
