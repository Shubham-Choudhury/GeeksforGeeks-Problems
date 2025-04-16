# Link: https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1


class Solution:
    def findMinCycle(self, V, edges):
        graph = [[] for _ in range(V)]
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))

        INF = float("inf")
        min_cycle = INF

        for u, v, w in edges:
            graph[u] = [pair for pair in graph[u] if pair != (v, w)]
            graph[v] = [pair for pair in graph[v] if pair != (u, w)]

            dist = [INF] * V
            visited = [False] * V
            dist[u] = 0

            for _ in range(V):
                min_dist = INF
                min_node = -1
                for i in range(V):
                    if not visited[i] and dist[i] < min_dist:
                        min_dist = dist[i]
                        min_node = i

                if min_node == -1:
                    break

                visited[min_node] = True

                for neighbor, weight in graph[min_node]:
                    if (
                        not visited[neighbor]
                        and dist[neighbor] > dist[min_node] + weight
                    ):
                        dist[neighbor] = dist[min_node] + weight

            if dist[v] != INF:
                min_cycle = min(min_cycle, dist[v] + w)

            graph[u].append((v, w))
            graph[v].append((u, w))

        return min_cycle if min_cycle != INF else -1


if __name__ == "__main__":
    obj = Solution()
    V = 5
    edges = [[0, 1, 2], [1, 2, 2], [1, 3, 1], [1, 4, 1], [0, 4, 3], [2, 3, 4]]
    print(obj.findMinCycle(V, edges))

    V = 5
    edges = [
        [0, 1, 3],
        [1, 2, 2],
        [0, 4, 1],
        [1, 4, 2],
        [1, 3, 1],
        [3, 4, 2],
        [2, 3, 3],
    ]
    print(obj.findMinCycle(V, edges))
