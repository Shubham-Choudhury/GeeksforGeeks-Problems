# Link: https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1


class Solution:
    def mergeArrays(self, a, b):
        n, m = len(a), len(b)
        i, j = n - 1, 0
        while i >= 0 and j < m:
            if a[i] > b[j]:
                a[i], b[j] = b[j], a[i]

            i -= 1
            j += 1

        a.sort()
        b.sort()


if __name__ == "__main__":
    object = Solution()
    a = [2, 4, 7, 10]
    b = [2, 3]
    object.mergeArrays(a, b)
    print(" ".join(map(str, a)))
    print(" ".join(map(str, b)))

    a = [1, 5, 9, 10, 15, 20]
    b = [2, 3, 8, 13]
    object.mergeArrays(a, b)
    print(" ".join(map(str, a)))
    print(" ".join(map(str, b)))

    a = [0, 1]
    b = [2, 3]
    object.mergeArrays(a, b)
    print(" ".join(map(str, a)))
    print(" ".join(map(str, b)))
