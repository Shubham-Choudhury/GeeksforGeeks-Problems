# Link: https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1


class Solution:
    # Function to detect cycle using DSU in an undirected graph.
    def detectCycle(self, V, adj):
        # Code here
        parent = list(range(V))
        rank = [1] * V

        def find(u):
            root = u
            while root != parent[root]:
                root = parent[root]

            while u != root:
                u, parent[u] = parent[u], root
            return root

        def union(u, v):
            u_root = find(u)
            v_root = find(v)
            if u_root == v_root:
                return u_root

            if rank[u_root] < rank[v_root]:
                u_root, v_root = v_root, u_root
            parent[v_root] = u_root
            rank[u_root] += rank[v_root]
            return u_root

        for u in range(V):
            for v in set(adj[u]):
                if v < u:
                    continue
                u_root = find(u)
                v_root = find(v)
                if u_root == v_root:
                    return 1
                union(u_root, v_root)

        return 0

if __name__=="__main__":
    obj=Solution()
    V=5
    adj=[[],[],[],[],[]]
    adj[0].append(1)
    adj[1].append(2)
    adj[2].append(3)
    adj[3].append(4)
    adj[4].append(1)
    print(obj.detectCycle(V,adj))