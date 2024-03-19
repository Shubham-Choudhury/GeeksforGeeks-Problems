# Link: https://www.geeksforgeeks.org/problems/possible-paths--141628/1


class Solution:
    def maximumWeight(self, n, edges, q, queries):
        uf = list(range(n))
        sz = [1] * n

        def find(u):
            if uf[u] != u:
                uf[u] = find(uf[u])
            return uf[u]

        edges.sort(key=lambda x: x[2], reverse=True)
        queries = sorted(enumerate(queries), key=lambda x: x[1])

        res = [0] * q
        cur = 0
        for ind, x in queries:
            while edges and edges[-1][2] <= x:
                u, v, _ = edges.pop()
                u, v = find(u - 1), find(v - 1)
                if u != v:
                    uf[u] = v
                    cur += sz[u] * sz[v]
                    sz[v] += sz[u]
            res[ind] = cur

        return res


if __name__ == "__main__":
    obj = Solution()
    n = 3
    edges = [[1, 2, 1], [2, 3, 4]]
    q = 1
    queries = [3]
    print(obj.maximumWeight(n, edges, q, queries))
    n = 7
    edges = [[1, 2, 3], [2, 3, 1], [2, 4, 9], [3, 6, 7], [3, 5, 8], [5, 7, 4]]
    q = 3
    queries = [1, 3, 5]
    print(obj.maximumWeight(n, edges, q, queries))
