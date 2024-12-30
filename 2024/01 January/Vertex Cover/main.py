# Link: https://www.geeksforgeeks.org/problems/vertex-cover/1

from typing import List


class Solution:
    def checkCover(self, n, k, m, e):
        set_val = (1 << k) - 1
        limit = 1 << n
        while set_val < limit:
            visited = [[False] * (n + 1) for _ in range(n + 1)]

            cnt = 0
            v = 1
            j = 1
            while j < limit:
                if set_val & j:
                    for k in range(1, n + 1):
                        if e[v][k] and not visited[v][k]:
                            visited[v][k] = True
                            visited[k][v] = True
                            cnt += 1

                j <<= 1
                v += 1

            if cnt == m:
                return True

            c = set_val & -set_val
            r = set_val + c
            set_val = (((r ^ set_val) >> 2) // c) | r

        return False

    def vertexCoverHelper(self, e, n, m):
        low, high = 1, n
        while high > low:
            mid = (low + high) >> 1
            if not self.checkCover(n, mid, m, e):
                low = mid + 1
            else:
                high = mid

        return low

    def vertexCover(self, n: int, edges: List[List[int]]) -> int:
        m = len(edges)

        e = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(m):
            e[edges[i][0]][edges[i][1]] = 1
            e[edges[i][1]][edges[i][0]] = 1

        return self.vertexCoverHelper(e, n, m)


if __name__ == "__main__":
    obj = Solution()
    N = 5
    M = 6
    edges = [[1, 2], [4, 1], [2, 4], [3, 4], [5, 2], [1, 3]]
    print(obj.vertexCover(N, edges))
    N = 2
    M = 1
    edges = [[1, 2]]
    print(obj.vertexCover(N, edges))
