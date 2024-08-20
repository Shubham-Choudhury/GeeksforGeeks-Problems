# Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

from collections import deque
import sys


class Solution:
    def shortestPath(self, edges, n, m, src):
        adj = [[] for _ in range(n)]
        for i in range(m):
            adj[edges[i][0]].append(edges[i][1])
            adj[edges[i][1]].append(edges[i][0])

        dist = [sys.maxsize] * n

        q = deque()
        q.append((src, 0))
        dist[src] = 0

        while q:
            node = q.popleft()

            if node[1] < dist[node[0]]:
                dist[node[0]] = node[1]

            for it in adj[node[0]]:
                if node[1] + 1 < dist[it]:
                    dist[it] = node[1] + 1
                    q.append((it, node[1] + 1))

        for i in range(n):
            if dist[i] == sys.maxsize:
                dist[i] = -1

        return dist


if __name__ == "__main__":
    obj = Solution()
    n = 9
    m = 10
    edges = [
        [0, 1],
        [0, 3],
        [3, 4],
        [4, 5],
        [5, 6],
        [1, 2],
        [2, 6],
        [6, 7],
        [7, 8],
        [6, 8],
    ]
    src = 0
    ans = obj.shortestPath(edges, n, m, src)
    print(" ".join(map(str, ans)))

    n = 4
    m = 2
    edges = [[1, 3], [3, 0]]
    src = 3

    ans = obj.shortestPath(edges, n, m, src)
    print(" ".join(map(str, ans)))
