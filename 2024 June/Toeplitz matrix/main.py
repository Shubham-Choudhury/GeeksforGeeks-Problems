# Link: https://www.geeksforgeeks.org/problems/toeplitz-matrix/1


def isToepliz(mat):
    r = len(mat)
    c = len(mat[0])
    for j in range(c):
        const = mat[0][j]
        for i in range(1, r):
            if i < r and i + j < c and mat[i][i + j] != const:
                return 0
    return 1


if __name__ == "__main__":
    mat = [[6, 7, 8], [4, 6, 7], [1, 4, 6]]
    print(isToepliz(mat))
    mat = [[1, 2, 3], [4, 5, 6]]
