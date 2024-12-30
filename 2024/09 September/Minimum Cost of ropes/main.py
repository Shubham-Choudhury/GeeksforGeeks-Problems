# Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

import heapq
from typing import List

class Solution:
    def minCost(self, arr: List[int]) -> int:
        n = len(arr)

        if n == 1:
            return 0

        heapq.heapify(arr)

        sum_cost = 0

        while len(arr) > 1:
            a1 = heapq.heappop(arr)
            a2 = heapq.heappop(arr)
            a3 = a1 + a2
            sum_cost += a3
            heapq.heappush(arr, a3)

        return sum_cost

if __name__ == "__main__":
    obj = Solution()
    arr = [4, 3, 2, 6]
    print(obj.minCost(arr))

    arr = [4, 2, 7, 6, 9]
    print(obj.minCost(arr))

