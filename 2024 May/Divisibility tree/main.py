# Link: https://www.geeksforgeeks.org/problems/divisibility-tree1902/1

from typing import List


class Solution:
    def dfs(self, adj: List[List[int]], u: int, prt: int, ans: List[int]) -> int:
        count = 0
        for v in adj[u]:
            if v != prt:
                x = self.dfs(adj, v, u, ans)
                if x % 2 == 0:
                    ans[0] += 1
                else:
                    count += x
        return count + 1

    def minimumEdgeRemove(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        for edge in edges:
            adj[edge[1] - 1].append(edge[0] - 1)
            adj[edge[0] - 1].append(edge[1] - 1)

        ans = [0]
        self.dfs(adj, 0, -1, ans)
        return ans[0]


if __name__ == "__main__":
    obj = Solution()
    edges = [[2, 1], [3, 1], [4, 3], [5, 2], [6, 1], [7, 2], [8, 6], [9, 8], [10, 8]]
    n = 10
    print(obj.minimumEdgeRemove(n, edges))

    edges = [[2, 1], [4, 2], [1, 3]]
    n = 4
    print(obj.minimumEdgeRemove(n, edges))
