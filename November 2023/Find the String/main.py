# Link: https://www.geeksforgeeks.org/problems/find-the-string/1


class Solution:
    def dfs(self, k, prev, seen, edges):
        for i in range(k):
            cur = prev + str(i)
            if cur not in seen:
                seen.add(cur)
                self.dfs(k, cur[1:], seen, edges)
                edges.append(i)

    def findString(self, N, K):
        seen = set()
        startingNode = "0" * (N - 1)
        edges = []
        self.dfs(K, startingNode, seen, edges)
        ret = ""
        l = K**N
        for i in range(l):
            ret += str(edges[i])
        ret += startingNode
        return ret


if __name__ == "__main__":
    obj = Solution()
    print(obj.findString(2, 2))
    print(obj.findString(2, 3))
