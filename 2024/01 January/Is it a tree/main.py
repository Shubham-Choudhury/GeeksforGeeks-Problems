# Link: https://www.geeksforgeeks.org/problems/is-it-a-tree/1


class Solution:
    def ispossible(self, adj, m, n, vis, node, par):
        vis.add(node)
        for nodes in adj[node]:
            if nodes not in vis:
                if not self.ispossible(adj, m, n, vis, nodes, node):
                    return 0
            elif nodes != par:
                return 0
        return 1

    def isTree(self, n, m, edges):
        if not edges:
            return 1 if n == 1 else 0
        vis = set()
        adj = [[] for i in range(n)]
        for i in range(m):
            adj[edges[i][0]].append(edges[i][1])
            adj[edges[i][1]].append(edges[i][0])
        res = self.ispossible(adj, m, n, vis, 0, -1)
        if len(vis) != n:
            return 0
        return res


if __name__ == "__main__":
    obj = Solution()
    N = 4
    M = 3
    G = [[0, 1], [1, 2], [1, 3]]
    print(obj.isTree(N, M, G))
