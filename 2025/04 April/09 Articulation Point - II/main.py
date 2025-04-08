# Link: https://www.geeksforgeeks.org/problems/articulation-point2616/1


class Solution:
    def __init__(self):
        self.timer = 1

    def dfs(self, node, parent, adj, visited, low, tn, mark):
        visited[node] = 1
        low[node] = tn[node] = self.timer
        self.timer += 1
        child = 0

        for it in adj[node]:
            if it == parent:
                continue
            if not visited[it]:
                self.dfs(it, node, adj, visited, low, tn, mark)
                low[node] = min(low[node], low[it])
                if low[it] >= tn[node] and parent != -1:
                    mark[node] = 1
                child += 1
            else:
                low[node] = min(low[node], tn[it])

        if child > 1 and parent == -1:
            mark[node] = 1

    def articulationPoints(self, V, edges):
        visited = [0] * V
        adj = [[] for _ in range(V)]
        for it in edges:
            adj[it[0]].append(it[1])
            adj[it[1]].append(it[0])

        low = [0] * V
        tn = [0] * V
        mark = [0] * V

        for i in range(V):
            if not visited[i]:
                self.dfs(i, -1, adj, visited, low, tn, mark)

        ans = [i for i in range(V) if mark[i] == 1]

        if not ans:
            return [-1]
        return ans


if __name__ == "__main__":
    sol = Solution()
    V = 5
    edges = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]
    print(sol.articulationPoints(V, edges))

    V = 4
    edges = [[0, 1], [0, 2]]
    print(sol.articulationPoints(V, edges))
