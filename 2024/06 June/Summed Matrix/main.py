# Link: https://www.geeksforgeeks.org/problems/summed-matrix5834/1


class Solution:
    def sumMatrix(self, n, q):
        if q == 1 or q > 2 * n:
            return 0
        return q - 1 if q <= n + 1 else 2 * n - q + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumMatrix(4, 7))
    print(obj.sumMatrix(5, 4))
