# Link: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

class Solution:
    def spirallyTraverse(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        result = []

        if m == 0:
            return result

        seen = [[False] * n for _ in range(m)]

        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]
        r, c = 0, 0
        di = 0

        for i in range(m * n):
            result.append(matrix[r][c])
            seen[r][c] = True
            newR, newC = r + dr[di], c + dc[di]

            if 0 <= newR < m and 0 <= newC < n and not seen[newR][newC]:
                r, c = newR, newC
            else:
                di = (di + 1) % 4
                r += dr[di]
                c += dc[di]
        return result


if __name__ == "__main__":
    obj = Solution()
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    print(obj.spirallyTraverse(matrix))
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    print(obj.spirallyTraverse(matrix))
