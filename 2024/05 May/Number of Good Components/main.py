# Link: https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1

from typing import List


class Solution:
    def findNumberOfGoodComponent(self, e: int, v: int, edges: List[List[int]]) -> int:
        ans = 0
        visited = [0] * (v + 1)

        adj = [[] for _ in range(v + 1)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        for i in range(1, v + 1):
            if visited[i] == 0:
                vertices = 0
                edgesCount = 0

                stk = [i]
                visited[i] = 1

                while stk:
                    node = stk.pop()
                    vertices += 1
                    edgesCount += len(adj[node])

                    for neighbor in adj[node]:
                        if visited[neighbor] == 0:
                            stk.append(neighbor)
                            visited[neighbor] = 1

                edgesCount //= 2
                if edgesCount == (vertices * (vertices - 1)) // 2:
                    ans += 1

        return ans


if __name__ == "__main__":
    obj = Solution()

    edges = [[1, 2], [1, 3], [3, 2]]
    e, v = 3, 3
    print(obj.findNumberOfGoodComponent(e, v, edges))

    edges = [[1, 2], [7, 2], [3, 5], [3, 4], [4, 5]]
    e, v = 5, 7
    print(obj.findNumberOfGoodComponent(e, v, edges))
