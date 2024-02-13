# Link: https://www.geeksforgeeks.org/problems/critical-connections/1

import sys


class Solution:
    def criticalConnections(self, v, adj):
        def Articulation_Point(u):
            low[u] = time[0]
            disc[u] = time[0]
            time[0] += 1
            visited[u] = True
            for v in adj[u]:
                if visited[v] == False:
                    parent[v] = u
                    Articulation_Point(v)

                    low[u] = min(low[u], low[v])

                    if low[v] > disc[u]:
                        ans.append(sorted([u, v]))

                elif parent[u] != v:
                    low[u] = min(low[u], disc[v])

        ans = []

        low = [sys.maxsize for i in range(v)]
        disc = [sys.maxsize for i in range(v)]
        parent = [-1 for i in range(v)]
        time = [0]
        visited = [False for i in range(v)]

        for i in range(v):
            if visited[i] == False:
                Articulation_Point(i)
        return sorted(ans)


if __name__ == "__main__":
    obj = Solution()
    v = 4
    adj = [[1, 0], [2, 0], [3, 1], [2, 1], [3, 2]]
    print(obj.criticalConnections(v, adj))
