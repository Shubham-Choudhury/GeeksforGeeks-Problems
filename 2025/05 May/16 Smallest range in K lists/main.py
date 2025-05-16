# Link: https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

import heapq


class Solution:
    def findSmallestRange(self, arr):
        k = len(arr)
        n = len(arr[0])
        heap = []
        maxVal = float("-inf")

        for i in range(k):
            heapq.heappush(heap, (arr[i][0], i, 0))
            maxVal = max(maxVal, arr[i][0])

        minRange = float("inf")
        minEl = maxEl = -1

        while True:
            minVal, row, col = heapq.heappop(heap)

            if maxVal - minVal < minRange:
                minRange = maxVal - minVal
                minEl = minVal
                maxEl = maxVal

            if col + 1 == n:
                break

            nextVal = arr[row][col + 1]
            heapq.heappush(heap, (nextVal, row, col + 1))
            maxVal = max(maxVal, nextVal)

        return [minEl, maxEl]


if __name__ == "__main__":
    obj = Solution()
    arr = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]
    result = obj.findSmallestRange(arr)
    print(result)

    arr = [[1, 3, 5, 7, 9], [0, 2, 4, 6, 8], [2, 3, 5, 7, 11]]
    result = obj.findSmallestRange(arr)
    print(result)

    arr = [[2, 4], [1, 7], [20, 40]]
    result = obj.findSmallestRange(arr)
    print(result)
