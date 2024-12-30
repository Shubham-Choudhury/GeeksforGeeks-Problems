# Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1


class Solution:
    def merge(self, v, l, mid, r):
        n1 = mid - l + 1
        n2 = r - mid
        v1 = v[l : l + n1]
        v2 = v[mid + 1 : mid + 1 + n2]
        i = 0
        j = 0
        n = l
        count = 0
        while i < n1 and j < n2:
            if v1[i] <= v2[j]:
                v[n] = v1[i]
                i += 1
                n += 1
            else:
                v[n] = v2[j]
                j += 1
                n += 1
                count += n1 - i

        while i < n1:
            v[n] = v1[i]
            i += 1
            n += 1
        while j < n2:
            v[n] = v2[j]
            j += 1
            n += 1
        return count

    def mergesort(self, v, l, r):
        count = 0
        if l < r:
            mid = (l + r) // 2
            count += self.mergesort(v, l, mid)
            count += self.mergesort(v, mid + 1, r)
            count += self.merge(v, l, mid, r)
        return count

    def inversionCount(self, arr):
        return self.mergesort(arr, 0, len(arr) - 1)


if __name__ == "__main__":
    object = Solution()
    v = [2, 4, 1, 3, 5]
    print(object.inversionCount(v))

    v = [2, 3, 4, 5, 6]
    print(object.inversionCount(v))

    v = [10, 10, 10]
    print(object.inversionCount(v))
