# Link: https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1


class Solution:
    def __init__(self):
        self.timer = 0
        self.tin = []
        self.low = []
        self.foundBridge = False

    def dfs(self, node, parent, adj, c, d):
        self.tin[node] = self.low[node] = self.timer
        self.timer += 1

        for neighbor in adj[node]:
            if neighbor == parent:
                continue

            if self.tin[neighbor] == -1:
                self.dfs(neighbor, node, adj, c, d)
                self.low[node] = min(self.low[node], self.low[neighbor])

                if self.low[neighbor] > self.tin[node]:
                    if (node == c and neighbor == d) or (node == d and neighbor == c):
                        self.foundBridge = True
            else:
                self.low[node] = min(self.low[node], self.tin[neighbor])

    def isBridge(self, V, edges, c, d):
        adj = [[] for _ in range(V)]

        for edge in edges:
            u, v = edge
            adj[u].append(v)
            adj[v].append(u)

        self.timer = 0
        self.tin = [-1] * V
        self.low = [-1] * V
        self.foundBridge = False

        for i in range(V):
            if self.tin[i] == -1:
                self.dfs(i, -1, adj, c, d)

        return self.foundBridge


if __name__ == "__main__":
    sol = Solution()
    c = 1
    d = 2
    V = 4
    edges = [[0, 1], [1, 2], [2, 3]]
    print(sol.isBridge(V, edges, c, d))

    c = 0
    d = 2
    V = 5
    edges = [[0, 1], [1, 2], [0, 2], [0, 3], [3, 4]]
    print(sol.isBridge(V, edges, c, d))
