# Link: https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1


class Solution:
    def findSwapValues(self, a, n, b, m):
        suma = sum(a)
        sumb = sum(b)
        if sumb > suma:
            a, b = b, a
            suma, sumb = sumb, suma
        if (suma - sumb) % 2 != 0:
            return -1
        diff = (sumb - suma) // 2
        setA = set(a)
        for bx in b:
            ax = bx - diff
            if ax in setA:
                return 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    a = [4, 1, 2, 1, 1, 2]
    b = [3, 6, 3, 3]
    n = len(a)
    m = len(b)
    print(obj.findSwapValues(a, n, b, m))

    a = [5, 7, 4, 6]
    b = [1, 2, 3, 8]
    n = len(a)
    m = len(b)
    print(obj.findSwapValues(a, n, b, m))
