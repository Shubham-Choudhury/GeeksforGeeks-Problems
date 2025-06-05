# Link: https://www.geeksforgeeks.org/problems/count-the-paths4332/1

from collections import deque


class Solution:
    def countPaths(self, edges, V, src, dest):
        graph = [[] for _ in range(V)]
        indegree = [0] * V

        for u, w in edges:
            graph[u].append(w)
            indegree[w] += 1

        q = deque()

        for i in range(V):
            if indegree[i] == 0:
                q.append(i)

        topo = []

        while q:
            node = q.popleft()
            topo.append(node)
            for nei in graph[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)

        dp = [0] * V
        dp[dest] = 1

        for node in reversed(topo):
            for nei in graph[node]:
                dp[node] += dp[nei]

        return dp[src]


if __name__ == "__main__":
    obj = Solution()
    edges = [[0, 1], [0, 3], [2, 0], [2, 1], [1, 3]]
    V = 4
    src = 2
    dest = 3
    print(obj.countPaths(edges, V, src, dest))

    edges = [[0, 1], [1, 2], [1, 3], [2, 3]]
    V = 4
    src = 0
    dest = 3
    print(obj.countPaths(edges, V, src, dest))
