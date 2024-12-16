# Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


class Solution:
    def kthElement(self, a, b, k):
        n, m = len(a), len(b)
        arr = []
        i, j, d = 0, 0, 0

        while i < n and j < m:
            if a[i] < b[j]:
                arr.append(a[i])
                i += 1
            else:
                arr.append(b[j])
                j += 1

        while i < n:
            arr.append(a[i])
            i += 1

        while j < m:
            arr.append(b[j])
            j += 1

        return arr[k - 1]


if __name__ == "__main__":
    object = Solution()
    a = [2, 3, 6, 7, 9]
    b = [1, 4, 8, 10]
    k = 5
    print(object.kthElement(a, b, k))

    a = [100, 112, 256, 349, 770]
    b = [72, 86, 113, 119, 265, 445, 892]
    k = 7
    print(object.kthElement(a, b, k))
