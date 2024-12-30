# Link: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

from collections import defaultdict
from heapq import heappush, heappop
from math import inf


class Solution:
    def shortestPath(self, n: int, m: int, edges: list[list[int]]) -> list[int]:
        # Create adjacency list
        adj = defaultdict(list)
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))

        # Dijkstra's algorithm
        dist = [inf] * (n + 1)
        dist[1] = 0
        pq = [(0, 1)]
        parent = [-1] * (n + 1)

        while pq:
            d, u = heappop(pq)
            if d > dist[u]:
                continue

            for v, w in adj[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    heappush(pq, (dist[v], v))
                    parent[v] = u

        # Reconstruct the shortest path
        if parent[n] == -1:
            return [-1]

        path = []
        node = n
        while node != -1:
            path.append(node)
            node = parent[node]
        path.append(dist[n])
        return path[::-1]


if __name__ == "__main__":
    obj = Solution()
    n = 5
    edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
    m = len(edges)
    print(obj.shortestPath(n, m, edges))

    n = 2
    edges = [[1, 2, 2]]
    m = len(edges)
    print(obj.shortestPath(n, m, edges))

    n = 2
    edges = []
    m = len(edges)
    print(obj.shortestPath(n, m, edges))
