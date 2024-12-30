# Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


class Solution:
    def findPath(self, mat):
        n = len(mat)
        visited = [[0 for i in range(n)] for j in range(n)]
        paths = []

        def helper(row, col, path):
            if mat[row][col] == 0:
                return
            if row == n - 1 and col == n - 1:
                paths.append(path)

            visited[row][col] = 1
            if 0 <= row + 1 < n and 0 <= col < n and not visited[row + 1][col]:
                helper(row + 1, col, path + "D")
            if 0 <= row - 1 < n and 0 <= col < n and not visited[row - 1][col]:
                helper(row - 1, col, path + "U")
            if 0 <= row < n and 0 <= col + 1 < n and not visited[row][col + 1]:
                helper(row, col + 1, path + "R")
            if 0 <= row < n and 0 <= col - 1 < n and not visited[row][col - 1]:
                helper(row, col - 1, path + "L")
            visited[row][col] = 0

        helper(0, 0, "")
        if paths:
            return paths
        else:
            return [-1]


if __name__ == "__main__":
    obj = Solution()
    mat = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
    ans = obj.findPath(mat)
    for i in ans:
        print(i, end=" ")
    print()

    mat = [[1, 0], [1, 0]]
    ans = obj.findPath(mat)
    for i in ans:
        print(i, end=" ")
    print()
