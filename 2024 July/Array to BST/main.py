# Link: https://www.geeksforgeeks.org/problems/array-to-bst4443/1

from collections import deque


# Tree Node
class Node:

    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def help(root, up, l):
    if root.data >= up or root.data <= l:
        return False
    ans = True
    if root.left:
        ans = help(root.left, root.data, l)
    if ans and root.right:
        ans = help(root.right, up, root.data)
    return ans


def isValidBST(root):
    return help(root, 3147483648, -3147483649)


def height(root):
    if root is None:
        return 0

    leftHeight = height(root.left)
    rightHeight = height(root.right)

    if leftHeight == -1 or rightHeight == -1 or abs(leftHeight - rightHeight) > 1:
        return -1

    return max(leftHeight, rightHeight) + 1


def isBalanced(root):
    if root is None:
        return True

    return height(root) != -1


def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input string after splitting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size += 1

    # Starting from the second element
    i = 1
    while size > 0 and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.popleft()
        size -= 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))
            # Push it to the queue
            q.append(currNode.left)
            size += 1

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))
            # Push it to the queue
            q.append(currNode.right)
            size += 1
        i += 1
    return root


class Solution:
    def solve(self, s, e, nums):
        if s >= e:
            return None
        mid = (s + e) // 2
        root = Node(nums[mid])
        root.left = self.solve(s, mid - 1, nums)
        root.right = self.solve(mid + 1, e, nums)
        return root

    def sortedArrayToBST(self, nums):
        n = len(nums)
        root = self.solve(0, n - 1, nums)
        return root


if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5, 6, 7]
    obj = Solution()
    root = obj.sortedArrayToBST(nums)
    print(isValidBST(root))
    print(isBalanced(root))

    nums = [1, 2, 3, 4]
    root = obj.sortedArrayToBST(nums)
    print(isValidBST(root))
    print(isBalanced(root))
