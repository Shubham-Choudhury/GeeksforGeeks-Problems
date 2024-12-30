class ListNode:
    # Constructor to create a new node
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


# Tree Node structure
class Tree:
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Class to convert the linked list to Binary Tree
class Conversion:
    # Constructor for storing head of linked list
    # and root for the Binary Tree
    def __init__(self, data=None):
        self.head = None
        self.root = None

    def push(self, new_data):
        # Creating a new linked list node and storing data
        new_node = ListNode(new_data)
        # Make next of new node as head
        new_node.next = self.head
        # Move the head to point to new node
        self.head = new_node

    def levelorderTraversal(self, root):
        mylist = []  # reverse list of nodes
        if root is None:
            return
        que = []
        que.append(root)
        while True:
            n = len(que)
            if n == 0:
                break
            while n > 0:
                node = que.pop(0)
                mylist.append(node.data)
                if node.left is not None:
                    que.append(node.left)
                if node.right is not None:
                    que.append(node.right)
                n -= 1
        mylist = mylist[::-1]
        print(*mylist)
        return


def createLinkedList(arr):
    head = None
    for i in range(len(arr) - 1, -1, -1):
        head = ListNode(arr[i], head)
    return head


def printTree(root):
    if root is None:
        return
    print(root.data, end=" ")
    printTree(root.left)
    printTree(root.right)


def convert(head):
    if not head:
        return None

    root = Tree(head.data)
    head = head.next

    queue = []
    queue.append(root)

    while head:
        current_parent = queue.pop(0)
        left_child = Tree(head.data)
        current_parent.left = left_child
        queue.append(left_child)
        head = head.next

        if head:
            right_child = Tree(head.data)
            current_parent.right = right_child
            queue.append(right_child)
            head = head.next

    return root


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    head = createLinkedList(arr)
    root = convert(head)
    printTree(root)
    print()

    arr = [5, 4, 3, 2, 1]
    head = createLinkedList(arr)
    root = convert(head)
    printTree(root)
