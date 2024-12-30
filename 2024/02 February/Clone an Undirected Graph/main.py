# Link: https://www.geeksforgeeks.org/problems/clone-graph/1


class Node:
    def __init__(self, val=0, neighbors=[]):
        self.val = val
        self.neighbors = neighbors


class Solution:
    def cloneGraph(self, node):
        from sys import setrecursionlimit

        setrecursionlimit(10**4)
        corr = dict()
        q = [node]
        while q:
            cur = q.pop()
            corr[cur] = Node()
            for nxt in cur.neighbors:
                if nxt not in corr:
                    q.append(nxt)
        for ex, ne in corr.items():
            ne.val = ex.val
            ne.neighbors = [corr[x] for x in ex.neighbors]
        return corr[node]

if __name__=="__main__":
    obj = Solution()
    node = Node(1, [Node(2), Node(3)])
    print(obj.cloneGraph(node))
    

    
