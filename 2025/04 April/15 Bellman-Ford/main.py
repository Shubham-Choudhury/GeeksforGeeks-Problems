# Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


class Solution:
    def bellmanFord(self, V, edges, src):
        INF = 10**8
        dist = [INF for _ in range(V)]
        dist[src] = 0

        for _ in range(V - 1):
            for s, e, dis in edges:
                if dist[s] != INF and dist[s] + dis < dist[e]:
                    dist[e] = dist[s] + dis

        for s, e, dis in edges:
            if dist[s] != INF and dist[s] + dis < dist[e]:
                return [-1]

        return dist


if __name__ == "__main__":
    obj = Solution()
    V = 5
    edges = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]]
    src = 0
    result = obj.bellmanFord(V, edges, src)
    print(result)

    V = 4
    edges = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]]
    src = 0
    result = obj.bellmanFord(V, edges, src)
    print(result)
