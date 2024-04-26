# Link: https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1


class Solution:
    def FindExitPoint(self, n, m, matrix):
        x = y = 0
        flag = 0
        while x >= 0 and y >= 0 and x < n and y < m:
            if matrix[x][y] == 1:
                flag = (flag + 1) % 4
                matrix[x][y] = 0
            if flag == 0:
                y += 1
            elif flag == 1:
                x += 1
            elif flag == 2:
                y -= 1
            else:
                x -= 1

        return max(min(x, n - 1), 0), max(min(y, m - 1), 0)


if __name__ == "__main__":
    obj = Solution()
    matrix = [[0, 1, 0], [0, 1, 1], [0, 0, 0]]
    n = len(matrix)
    m = len(matrix[0])
    print(obj.FindExitPoint(n, m, matrix))
    matrix = [[0, 0]]
    n = len(matrix)
    m = len(matrix[0])
    print(obj.FindExitPoint(n, m, matrix))
