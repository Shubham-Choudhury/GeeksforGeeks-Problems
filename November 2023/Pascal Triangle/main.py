# Link: https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

from math import factorial

class Solution:
    def nthRowOfPascalTriangle(self, n):
        pascal_row = []
        numerator = factorial(n - 1)

        for current_column in range(n):
            binomial_coefficient = numerator // (
                factorial(n - current_column - 1) * factorial(current_column)
            )
            pascal_element = binomial_coefficient % (10**9 + 7)
            pascal_row.append(pascal_element)
        return pascal_row


if __name__ == "__main__":
    obj = Solution()
    n = 4
    ans = obj.nthRowOfPascalTriangle(n)
    for i in range(len(ans)):
        print(ans[i], end=" ")
    print()
    n = 5
    ans = obj.nthRowOfPascalTriangle(n)
    for i in range(len(ans)):
        print(ans[i], end=" ")
    print()
