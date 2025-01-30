# Link: https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1


class Solution:
    def is_possible(self, grid, curr_row, curr_col, val):
        N = len(grid)
        for i in range(N):
            if grid[curr_row][i] == val:
                return False
            if grid[i][curr_col] == val:
                return False

        for i in range(N):
            if grid[3 * (curr_row // 3) + i // 3][3 * (curr_col // 3) + i % 3] == val:
                return False

        return True

    def helper(self, grid):
        N = len(grid)
        for i in range(N):
            for j in range(N):
                if grid[i][j] == 0:
                    for index in range(1, 10):
                        if self.is_possible(grid, i, j, index):
                            grid[i][j] = index
                            if self.helper(grid):
                                return True
                            else:
                                grid[i][j] = 0
                    if grid[i][j] == 0:
                        return False
        return True

    def solveSudoku(self, mat):
        self.helper(mat)


if __name__ == "__main__":
    object = Solution()
    mat = [
        [3, 0, 6, 5, 7, 8, 4, 0, 0],
        [5, 6, 0, 0, 0, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 0, 3, 1],
        [0, 0, 3, 0, 0, 1, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [0, 0, 5, 2, 8, 6, 3, 0, 0],
    ]

    object.solveSudoku(mat)

    for row in mat:
        print(" ".join(map(str, row)))
    print()

    mat = [
        [3, 1, 6, 5, 7, 8, 4, 9, 2],
        [5, 2, 9, 1, 3, 4, 7, 6, 8],
        [4, 8, 7, 6, 2, 9, 5, 3, 1],
        [2, 6, 3, 0, 1, 5, 9, 8, 7],
        [9, 7, 4, 8, 6, 0, 1, 2, 5],
        [8, 5, 1, 7, 9, 2, 6, 4, 3],
        [1, 3, 8, 0, 4, 7, 2, 0, 6],
        [6, 9, 2, 3, 5, 1, 8, 7, 4],
        [7, 4, 5, 0, 8, 6, 3, 1, 0],
    ]
    object.solveSudoku(mat)
    for row in mat:
        print(" ".join(map(str, row)))
    print()
