# Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1


class Solution:
    def celebrity(self, mat):
        n = len(mat)

        i = 0
        j = n - 1
        while i < j:
            if mat[j][i] == 1:
                j -= 1

            else:
                i += 1

        c = i

        for i in range(n):
            if i == c:
                continue

            if mat[c][i] or not mat[i][c]:
                return -1

        return c


if __name__ == "__main__":
    sol = Solution()
    mat = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
    result = sol.celebrity(mat)
    print("Celebrity index:", result)

    mat = [[1, 1], [1, 1]]
    result = sol.celebrity(mat)
    print("Celebrity index:", result)

    mat = [[1]]
    result = sol.celebrity(mat)
    print("Celebrity index:", result)
