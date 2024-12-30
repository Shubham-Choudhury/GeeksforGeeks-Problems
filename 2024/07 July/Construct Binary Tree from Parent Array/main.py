# Link: https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

from collections import deque


class Node:
    def __init__(self, data):
        self.key = data
        self.left = None
        self.right = None


def traverse_level_order(root):
    if root is None:
        return
    que = []
    que.append(root)
    while 1:
        n = len(que)
        if n == 0:
            break
        sorted_nodes = [node.key for node in que]
        sorted_nodes.sort()
        print(*sorted_nodes, end=" ")
        while n > 0:
            node = que.pop(0)
            if node.left != None:
                que.append(node.left)
            if node.right != None:
                que.append(node.right)
            n -= 1


class Solution:
    def createTree(self, parent):
        n = len(parent)
        mp = {}
        root = None

        for i in range(n):
            node = None
            if i in mp:
                node = mp[i]
            else:
                node = Node(i)
                mp[i] = node

            if parent[i] == -1:
                root = node
                continue

            if parent[i] in mp:
                if mp[parent[i]].left:
                    mp[parent[i]].right = node
                else:
                    mp[parent[i]].left = node
            else:
                temp = Node(parent[i])
                mp[parent[i]] = temp
                temp.left = node

        return root


if __name__ == "__main__":
    obj = Solution()
    parent = [-1, 0, 0, 1, 1, 3, 5]
    root = obj.createTree(parent)
    traverse_level_order(root)
    print()

    parent = [2, 0, -1]
    root = obj.createTree(parent)
    traverse_level_order(root)
