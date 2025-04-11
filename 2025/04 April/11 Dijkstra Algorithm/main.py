# Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


import heapq
import sys


class Solution:
    def dijkstra(self, V, edges, src):
        adj = [[] for _ in range(V)]
        dist = [sys.maxsize] * V
        hq = []
        for edge in edges:
            adj[edge[0]].append((edge[1], edge[2]))
            adj[edge[1]].append((edge[0], edge[2]))

        heapq.heapify(hq)
        heapq.heappush(hq, (0, src))
        dist[src] = 0
        while len(hq) > 0:
            weight, u = heapq.heappop(hq)
            if dist[u] < weight:
                continue
            for v, w in adj[u]:
                if weight + w < dist[v]:
                    dist[v] = weight + w
                    heapq.heappush(hq, (dist[v], v))
        return dist


if __name__ == "__main__":
    sol = Solution()
    V = 3
    edges = [[0, 1, 1], [1, 2, 3], [0, 2, 6]]
    src = 2
    result = sol.dijkstra(V, edges, src)
    print(result)

    V = 5
    edges = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]]
    src = 0
    result = sol.dijkstra(V, edges, src)
    print(result)
