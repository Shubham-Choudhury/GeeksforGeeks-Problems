# Link: https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1


class Solution:
    def isEulerCircuitExist(self, V, adj):
        # Code here
        c = 0

        for i in range(V):
            if len(adj[i]) % 2 != 0:
                c += 1
        if c == 0:
            return 2

        if c == 2:
            return 1
        return 0


if __name__ == "__main__":
    obj = Solution()
    tc = int(input())
    while tc > 0:
        V, E = map(int, input().strip().split())
        adj = [[] for i in range(V)]
        for i in range(E):
            u, v = map(int, input().strip().split())
            adj[u].append(v)
            adj[v].append(u)
        print(obj.isEulerCircuitExist(V, adj))
        tc = tc - 1
