# Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1


class Solution:
    def BoundaryTraversal(self, matrix, n, m):
        top = 0
        down = len(matrix) - 1
        left = 0
        right = len(matrix[0]) - 1
        result = []
        for i in range(left, right + 1):
            result.append(matrix[top][i])
        top += 1
        if top <= down:
            for j in range(top, down + 1):
                result.append(matrix[j][right])
            right -= 1
            if left <= right:
                for k in range(right, left - 1, -1):
                    result.append(matrix[down][k])
                down -= 1
                for l in range(down, top - 1, -1):
                    result.append(matrix[l][left])
        return result


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().strip().split())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix = []
        for i in range(n):
            row = []
            for j in range(m):
                row.append(values[k])
                k += 1
            matrix.append(row)
        obj = Solution()
        ans = obj.BoundaryTraversal(matrix, n, m)
        for i in ans:
            print(i, end=" ")
        print()
