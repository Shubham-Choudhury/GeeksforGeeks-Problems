# Link: https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

from typing import List


class Solution:
    def findCity(self, n: int, m: int, edges: List[List[int]], d: int) -> int:
        from collections import defaultdict
        from heapq import heappush, heappop

        g = defaultdict(list)

        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))

        def dijkstr(n):
            costs = {n: 0}
            q = [(0, n)]
            while q:
                cost0, n0 = heappop(q)
                for nbr, c in g[n0]:
                    cost = cost0 + c
                    if cost > d:
                        continue
                    if nbr not in costs or costs[nbr] > cost:
                        costs[nbr] = cost
                        heappush(q, (cost, nbr))
            return len(costs)

        ans = 0
        cnt = n
        for k in range(n):
            c = dijkstr(k)
            if c <= cnt:
                cnt = c
                ans = k
        return ans


if __name__ == "__main__":
    obj = Solution()
    edges = [[0, 1, 2], [0, 4, 8], [1, 2, 3], [1, 4, 2], [2, 3, 1], [3, 4, 1]]
    n, m, d = 5, 6, 2
    print(obj.findCity(n, m, edges, d))
    edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]]
    n, m, d = 4, 4, 4
    print(obj.findCity(n, m, edges, d))
