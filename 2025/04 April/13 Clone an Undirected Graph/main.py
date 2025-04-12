# Link: https://www.geeksforgeeks.org/problems/clone-graph/1

from queue import Queue
import sys

sys.setrecursionlimit(10**6)


class Node:

    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


def compare(prev, new, prev_vis=set(), new_vis=set()):
    if prev == new:
        return False
    if not prev or not new:
        if (not prev and new) or (prev and not new):
            return False
        return True

    if prev in prev_vis or new in new_vis:
        if (prev in prev_vis and new not in new_vis) or (
            prev not in prev_vis and new in new_vis
        ):
            return False
        return True
    prev_vis.add(prev)
    new_vis.add(new)

    if prev.val != new.val:
        return False

    prev_n = len(prev.neighbors)
    new_n = len(prev.neighbors)
    if prev_n != new_n:
        return False

    prev.neighbors.sort(key=lambda x: x.val)
    new.neighbors.sort(key=lambda x: x.val)
    for i in range(prev_n):
        if not compare(prev.neighbors[i], new.neighbors[i], prev_vis, new_vis):
            return False

    return True


class Solution:
    def cloneGraph(self, node):
        dic = dict()
        vis = set()

        def rec(nod):
            if nod not in vis:
                vis.add(nod)
                if nod.val not in dic:
                    dic[nod.val] = Node(nod.val, [])
                for i in nod.neighbors:
                    if i.val not in dic:
                        dic[i.val] = Node(i.val, [])
                    dic[nod.val].neighbors.append(dic[i.val])
                    rec(i)

        rec(node)
        return dic[node.val]


if __name__ == "__main__":
    solution = Solution()
    n = 4
    adjList = [[1, 2], [0, 2], [0, 1, 3], [2]]
    nodes = [Node(i) for i in range(n)]
    for i in range(n):
        for j in adjList[i]:
            nodes[i].neighbors.append(nodes[j])
    node = nodes[0]
    clone = solution.cloneGraph(node)
    if compare(node, clone):
        print("The clone is correct")
    else:
        print("The clone is incorrect")

    n = 3
    adjList = [[1, 2], [0], [0]]
    nodes = [Node(i) for i in range(n)]
    for i in range(n):
        for j in adjList[i]:
            nodes[i].neighbors.append(nodes[j])
    node = nodes[0]
    clone = solution.cloneGraph(node)
    if compare(node, clone):
        print("The clone is correct")
    else:
        print("The clone is incorrect")
