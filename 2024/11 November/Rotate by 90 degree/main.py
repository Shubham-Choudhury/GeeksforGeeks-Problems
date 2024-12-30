# Link: https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1


def rotate(matrix):
    n = len(matrix)
    m = len(matrix[0])
    for i in range(n - 1):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(n):
        for j in range(n // 2):
            matrix[i][j], matrix[i][m - j - 1] = matrix[i][m - j - 1], matrix[i][j]


matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
rotate(matrix)
for row in matrix:
    print(" ".join(map(str, row)))
print()

matrix = [[1, 2], [3, 4]]
rotate(matrix)
for row in matrix:
    print(" ".join(map(str, row)))
print()

matrix = [[1]]
rotate(matrix)
for row in matrix:
    print(" ".join(map(str, row)))
print()
