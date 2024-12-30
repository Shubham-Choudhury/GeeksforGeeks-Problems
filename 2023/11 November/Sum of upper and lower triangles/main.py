# Link: https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1


class Solution:
    def sumTriangles(self, matrix, n):
        # code here
        upper, lower = 0, 0
        for i in range(n):
            for j in range(n):
                if i <= j:
                    upper += matrix[i][j]
                if i >= j:
                    lower += matrix[i][j]
        return [upper, lower]


if __name__ == "__main__":
    obj = Solution()
    matrix = [[6, 5, 4], [1, 2, 5], [7, 9, 7]]
    n = 3
    print(obj.sumTriangles(matrix, n))
