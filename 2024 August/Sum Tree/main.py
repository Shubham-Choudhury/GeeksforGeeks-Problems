# Link: https://www.geeksforgeeks.org/problems/sum-tree/1

from collections import deque


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def new_node(val):
    return Node(val)


def build_tree(s):
    # Corner Case
    if not s or s[0] == "N":
        return None

    # Creating list of strings from input string after splitting by space
    ip = s.split()

    # Create the root of the tree
    root = new_node(int(ip[0]))

    # Push the root to the queue
    queue = []
    queue.append(root)

    # Starting from the second element
    i = 1
    while queue and i < len(ip):
        # Get and remove the front of the queue
        curr_node = queue.pop(0)

        # Get the current node's value from the string
        curr_val = ip[i]

        # If the left child is not null
        if curr_val != "N":
            # Create the left child for the current node
            curr_node.left = new_node(int(curr_val))

            # Push it to the queue
            queue.append(curr_node.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        curr_val = ip[i]

        # If the right child is not null
        if curr_val != "N":
            # Create the right child for the current node
            curr_node.right = new_node(int(curr_val))

            # Push it to the queue
            queue.append(curr_node.right)
        i += 1

    return root


class Solution:
    def check_three_sum(self, root, ans):
        if root.left is None and root.right is None:
            return root.data

        sum_left = 0
        sum_right = 0
        if root.right:
            sum_left = self.check_three_sum(root.right, ans)

        if root.left:
            sum_right = self.check_three_sum(root.left, ans)

        if root.data != sum_left + sum_right:
            ans[0] = False

        total_sum = root.data + sum_left + sum_right
        return total_sum

    def is_sum_tree(self, node):
        ans = [True]
        self.check_three_sum(node, ans)
        return ans[0]


if __name__ == "__main__":
    obj = Solution()
    s = "3 1 2"
    root = build_tree(s)
    print(obj.is_sum_tree(root))

    s = "10 20 30 10 10"
    root = build_tree(s)
    print(obj.is_sum_tree(root))
