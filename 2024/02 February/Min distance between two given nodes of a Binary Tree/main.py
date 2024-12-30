# Link: https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def lca(self, root, nodeA, nodeB):
        if not root or root.data == nodeA.data or root.data == nodeB.data:
            return root
        l = self.lca(root.left, nodeA, nodeB)
        r = self.lca(root.right, nodeA, nodeB)
        if not l:
            return r
        if not r:
            return l
        if not l and not r:
            return None

        return root

    def distanceFromNode(self, root, node, level=0):
        if not root:
            return -1
        if root.data == node.data:
            return level
        left = self.distanceFromNode(root.left, node, level + 1)
        if left != -1:
            return left
        return self.distanceFromNode(root.right, node, level + 1)

    def solve(self, root, nodeA, nodeB):
        lca = self.lca(root, nodeA, nodeB)
        if not lca:
            return -1
        distanceFromLcaToNodeA = self.distanceFromNode(lca, nodeA)
        distanceFromLcaToNodeB = self.distanceFromNode(lca, nodeB)
        totalDistanceFromNodeAtoNodeB = distanceFromLcaToNodeA + distanceFromLcaToNodeB
        return totalDistanceFromNodeAtoNodeB

    def findDist(self, root, a, b):
        return self.solve(root, Node(a), Node(b))


if __name__ == "__main__":
    obj = Solution()
    root = Node(11)
    root.left = Node(22)
    root.right = Node(33)
    root.left.left = Node(44)
    root.left.right = Node(55)
    root.right.left = Node(66)
    root.right.right = Node(77)
    a = 77
    b = 22
    print(obj.findDist(root, a, b))
