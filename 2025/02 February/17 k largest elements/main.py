# Link: https://www.geeksforgeeks.org/problems/k-largest-elements4206/1


class Solution:
    def kLargest(self, arr, k):
        arr.sort(reverse=True)
        return arr[:k]


if __name__ == "__main__":
    object = Solution()
    arr = [12, 5, 787, 1, 23]
    k = 2
    result = object.kLargest(arr, k)
    print(" ".join(map(str, result)))

    arr = [1, 23, 12, 9, 30, 2, 50]
    k = 3
    result = object.kLargest(arr, k)
    print(" ".join(map(str, result)))

    arr = [12, 23]
    k = 1
    result = object.kLargest(arr, k)
    print(" ".join(map(str, result)))
