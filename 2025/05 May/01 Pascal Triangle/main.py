# Link: https://www.geeksforgeeks.org/problems/pascal-triangle0652/1


class Solution:
    def nthRowOfPascalTriangle(self, n):
        n -= 1
        res = []
        prev = 1
        res.append(prev)

        for i in range(1, n + 1):
            curr = (prev * (n - i + 1)) // i
            res.append(curr)
            prev = curr

        return res


if __name__ == "__main__":
    obj = Solution()
    n = 4
    print(obj.nthRowOfPascalTriangle(n))
    n = 5
    print(obj.nthRowOfPascalTriangle(n))
    n = 1
    print(obj.nthRowOfPascalTriangle(n))
