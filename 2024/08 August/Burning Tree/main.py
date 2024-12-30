# Link: https://www.geeksforgeeks.org/problems/burning-tree/1

from collections import deque


# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while size > 0 and i < len(ip):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":

            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":

            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


class Solution:
    def find_target(self, root, target, parent_map):
        if not root:
            return None

        q = deque([root])
        parent_map[root] = None

        while q:
            current = q.popleft()

            if current.data == target:
                return current

            if current.left:
                parent_map[current.left] = current
                q.append(current.left)
            if current.right:
                parent_map[current.right] = current
                q.append(current.right)

        return None

    def bfs_burn_time(self, start_node, parent_map):
        if not start_node:
            return 0

        q = deque([start_node])
        visited = {start_node}
        max_time = 0

        while q:
            size = len(q)
            for _ in range(size):
                current = q.popleft()

                if current.left and current.left not in visited:
                    q.append(current.left)
                    visited.add(current.left)
                if current.right and current.right not in visited:
                    q.append(current.right)
                    visited.add(current.right)
                if current in parent_map:
                    parent = parent_map[current]
                    if parent and parent not in visited:
                        q.append(parent)
                        visited.add(parent)
            max_time += 1

        return max_time - 1

    def min_time(self, root, target):
        if not root:
            return 0

        parent_map = {}
        target_node = self.find_target(root, target, parent_map)

        if not target_node:
            return -1

        return self.bfs_burn_time(target_node, parent_map)


if __name__ == "__main__":
    obj = Solution()
    s = "1 2 3 4 5 6 N N N 7 8 9 N N N N N 10 N"
    root = buildTree(s)
    target = 8
    print(obj.min_time(root, target))

    s = "1 2 3 4 5 7 N 8 N 10 N"
    root = buildTree(s)
    target = 10
    print(obj.min_time(root, target))
