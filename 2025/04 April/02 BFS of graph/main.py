# Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


class Solution:
    def bfs(self, adj):
        queue = [0]
        visited = set([0])
        res = []

        while queue:
            node = queue.pop(0)
            res.append(node)

            for neighbor in adj[node]:
                if neighbor not in visited:
                    queue.append(neighbor)
                    visited.add(neighbor)

        return res


if __name__ == "__main__":
    obj = Solution()
    adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
    print(obj.bfs(adj))

    adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
    print(obj.bfs(adj))
