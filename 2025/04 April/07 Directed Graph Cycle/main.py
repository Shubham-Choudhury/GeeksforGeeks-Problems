# Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


class Solution:
    def isCycle(self, V, edges):
        in_degree = [0] * V
        graph = [[] for _ in range(V)]

        for u, v in edges:
            graph[u].append(v)
        for node_list in graph:
            for node in node_list:
                in_degree[node] += 1

        queue = []
        for i in range(V):
            if in_degree[i] == 0:
                queue.append(i)
        sorted_nodes = []
        while queue:
            current = queue.pop(0)
            sorted_nodes.append(current)
            for adj in graph[current]:
                in_degree[adj] -= 1
                if in_degree[adj] == 0:
                    queue.append(adj)
        return len(sorted_nodes) < V


if __name__ == "__main__":
    obj = Solution()
    V = 4
    edges = [[0, 1], [1, 2], [2, 3], [3, 3]]
    result = obj.isCycle(V, edges)
    if result:
        print("Cycle detected")
    else:
        print("No cycle detected")

    V = 3
    edges = [[0, 1], [1, 2]]
    result = obj.isCycle(V, edges)
    if result:
        print("Cycle detected")
    else:
        print("No cycle detected")
