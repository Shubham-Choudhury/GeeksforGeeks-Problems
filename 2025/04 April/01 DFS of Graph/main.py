# Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


class Solution:
    def dfs(self, adj):
        l = [-1 for i in range(len(adj))]
        result = []

        def depth(l, p, adj, result):
            for i in adj[p]:
                if l[i] == -1:
                    l[i] = 1
                    result.append(i)
                    depth(l, i, adj, result)

        l[0] = 1
        result.append(0)
        depth(l, 0, adj, result)
        return result


if __name__ == "__main__":
    obj = Solution()
    adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
    result = obj.dfs(adj)
    print(result)

    adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
    result = obj.dfs(adj)
    print(result)
