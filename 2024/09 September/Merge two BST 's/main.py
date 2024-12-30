# Link: https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input string after splitting by space
    ip = s.split()

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    queue = [root]

    # Starting from the second element
    i = 1
    while queue and i < len(ip):
        # Get and remove the front of the queue
        currNode = queue.pop(0)

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            queue.append(currNode.left)

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
            queue.append(currNode.right)
        i += 1

    return root


class Solution:
    def inorderIterative(self, ans, root):
        if not root:
            return

        st = []
        curr = root

        while curr is not None or st:
            while curr is not None:
                st.append(curr)
                curr = curr.left

            curr = st.pop()
            ans.append(curr.data)

            curr = curr.right

    def merge(self, root1, root2):
        ans = []
        self.inorderIterative(ans, root1)
        self.inorderIterative(ans, root2)
        ans.sort()
        return ans


if __name__ == "__main__":
    obj = Solution()
    s1 = "5 3 6 2 4"
    s2 = "2 1 3 N N N 7 6"
    root1 = buildTree(s1)
    root2 = buildTree(s2)
    ans = obj.merge(root1, root2)
    print(" ".join(map(str, ans)))

    s1 = "12 9 N 6 11"
    s2 = "8 5 10 2"
    root1 = buildTree(s1)
    root2 = buildTree(s2)
    ans = obj.merge(root1, root2)
    print(" ".join(map(str, ans)))
