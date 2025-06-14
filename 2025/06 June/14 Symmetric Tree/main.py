# Link: https://www.geeksforgeeks.org/problems/symmetric-tree/1


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


def createBinaryTree(s):
    if not s:
        return None

    nodes = s.split()
    if nodes[0] == "N":
        return None

    root = Node(int(nodes[0]))
    queue = [root]
    i = 1

    while i < len(nodes):
        current = queue.pop(0)

        if nodes[i] != "N":
            current.left = Node(int(nodes[i]))
            queue.append(current.left)
        i += 1

        if i < len(nodes) and nodes[i] != "N":
            current.right = Node(int(nodes[i]))
            queue.append(current.right)
        i += 1

    return root


class Solution:
    def isSymmetric(self, root):
        if not root:
            return True

        stack1 = [root.left]
        stack2 = [root.right]

        while stack1 and stack2:
            node1 = stack1.pop()
            node2 = stack2.pop()

            if not node1 and not node2:
                continue

            if not node1 or not node2 or node1.data != node2.data:
                return False

            stack1.append(node1.left)
            stack2.append(node2.right)

            stack1.append(node1.right)
            stack2.append(node2.left)

        return not stack1 and not stack2


# Test cases
if __name__ == "__main__":
    solution = Solution()
    s = "1 2 2 3 4 4 3"
    root = createBinaryTree(s)
    print(solution.isSymmetric(root))

    s = "1 2 2 N 3 N 3"
    root = createBinaryTree(s)
    print(solution.isSymmetric(root))
