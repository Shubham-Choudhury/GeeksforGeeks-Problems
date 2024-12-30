# Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1


class Solution:
    def celebrity(self, mat):
        n = len(mat)
        potential_celebrity = 0

        for i in range(1, n):
            if mat[potential_celebrity][i] == 1:
                potential_celebrity = i

        for i in range(n):
            if i != potential_celebrity:
                if mat[potential_celebrity][i] == 1 or mat[i][potential_celebrity] == 0:
                    return -1

        return potential_celebrity


if __name__ == "__main__":
    obj = Solution()
    mat = [[0, 1, 0], [0, 0, 0], [0, 1, 0]]
    print(obj.celebrity(mat))
    mat = [[0, 1], [1, 0]]
    print(obj.celebrity(mat))
