# Link: https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution:
    def topoSort(self, V, edges):
        adj = [[] for _ in range(V)]
        indegree = [0] * V

        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1

        q = []
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)

        res = []
        front = 0

        while front < len(q):
            node = q[front]
            front += 1
            res.append(node)

            for nei in adj[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)

        return res


if __name__ == "__main__":
    obj = Solution()
    V = 4
    E = 3
    edges = [[3, 0], [1, 0], [2, 0]]
    result = obj.topoSort(V, edges)
    print(result)

    V = 6
    E = 6
    edges = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]
    result = obj.topoSort(V, edges)
    print(result)
