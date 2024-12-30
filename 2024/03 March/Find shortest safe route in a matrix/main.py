# Link: https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1

from typing import List
from collections import deque


class Solution:
    def findShortestPath(self, mat: List[List[int]]) -> int:
        r, c = len(mat), len(mat[0])
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        q = deque()
        visited = [[False] * c for _ in range(r)]

        def isSafe(x, y):
            if 0 <= x < r and 0 <= y < c:
                if mat[x][y] == 1:
                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < r and 0 <= ny < c and mat[nx][ny] == 0:
                            return False
                    return True
            return False

        for i in range(r):
            if isSafe(i, 0):
                q.append((i, 0, 1))
                visited[i][0] = True

        while q:
            x, y, dist = q.popleft()
            if y == c - 1:
                return dist
            for dx, dy in directions:
                newX, newY = x + dx, y + dy
                if (
                    0 <= newX < r
                    and 0 <= newY < c
                    and not visited[newX][newY]
                    and isSafe(newX, newY)
                ):
                    visited[newX][newY] = True
                    q.append((newX, newY, dist + 1))

        return -1


if __name__ == "__main__":
    obj = Solution()
    mat = [
        [0, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
    ]
    print(obj.findShortestPath(mat))
