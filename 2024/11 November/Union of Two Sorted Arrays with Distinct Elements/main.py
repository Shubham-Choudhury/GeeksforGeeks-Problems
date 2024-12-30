# Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1


class Solution:
    def findUnion(self, a, b):
        result = []
        n, m = len(a), len(b)
        i, j = 0, 0
        while i < n and j < m:
            if a[i] < b[j]:
                result.append(a[i])
                i += 1
            elif a[i] > b[j]:
                result.append(b[j])
                j += 1
            else:
                result.append(a[i])
                i += 1
                j += 1
        while i < n:
            result.append(a[i])
            i += 1
        while j < m:
            result.append(b[j])
            j += 1
        return result


if __name__ == "__main__":
    object = Solution()
    a = [1, 2, 3, 4, 5]
    b = [1, 2, 3, 6, 7]
    result = object.findUnion(a, b)
    print(" ".join(map(str, result)))

    a = [2, 3, 4, 5]
    b = [1, 2, 3, 4]
    result = object.findUnion(a, b)
    print(" ".join(map(str, result)))

    a = [1]
    b = [2]
    result = object.findUnion(a, b)
    print(" ".join(map(str, result)))
