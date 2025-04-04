# Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


class Solution:
    def isCycle(self, V, edges):
        graph = {}
        for i in range(V):
            graph[i] = set()

        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)

        visited = set()

        def dfs(node, parent):
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor != parent:
                    if neighbor in visited:
                        return True
                    if dfs(neighbor, node):
                        return True
            return False

        for node in range(V):
            if node not in visited:
                if dfs(node, -1):
                    return True
        return False


if __name__ == "__main__":
    solution = Solution()
    V = 4
    E = 4
    edges = [[0, 1], [0, 2], [1, 2], [2, 3]]
    print(solution.isCycle(V, edges))

    V = 4
    E = 3
    edges = [[0, 1], [1, 2], [2, 3]]
    print(solution.isCycle(V, edges))
