# Link: https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1


class Solution:
    def matrixDiagonally(self, mat):
        n = len(mat)
        d = {}
        for i in range(n):
            for j in range(n):
                if i + j not in d:
                    d[i + j] = []
                d[i + j].append(mat[i][j])
        ans = []
        for key in d:
            if key % 2 == 0:
                ans.extend(d[key][::-1])
            else:
                ans.extend(d[key])
        return ans


if __name__ == "__main__":
    obj = Solution()
    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(obj.matrixDiagonally(mat))
    mat = [[1, 2], [3, 4]]
    print(obj.matrixDiagonally(mat))
