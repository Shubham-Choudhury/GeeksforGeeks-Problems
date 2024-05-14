# Link: https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

from typing import List
import heapq


class Solution:
    def MinimumEffort(self, rows: int, columns: int, heights: List[List[int]]) -> int:
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        pq = [(0, 0, 0)]
        min_efforts = [[float("inf")] * columns for _ in range(rows)]
        min_efforts[0][0] = 0

        while pq:
            effort, row, col = heapq.heappop(pq)
            if row == rows - 1 and col == columns - 1:
                return effort
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                if 0 <= new_row < rows and 0 <= new_col < columns:
                    new_effort = max(
                        effort, abs(heights[row][col] - heights[new_row][new_col])
                    )
                    if new_effort < min_efforts[new_row][new_col]:
                        min_efforts[new_row][new_col] = new_effort
                        heapq.heappush(pq, (new_effort, new_row, new_col))

        return -1


if __name__ == "__main__":
    obj = Solution()
    heights = [[1, 2, 2], [3, 8, 2], [5, 3, 5]]
    rows = len(heights)
    columns = len(heights[0])
    print(obj.MinimumEffort(rows, columns, heights))

    heights = [[7, 7], [7, 7]]
    rows = len(heights)
    columns = len(heights[0])
    print(obj.MinimumEffort(rows, columns, heights))
