# Link: https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1


class Node:

    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None
        temp = None

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_node):
        if self.head is None:
            self.head = new_node
            self.temp = self.head
            return
        else:
            self.temp.next = new_node
            self.temp = self.temp.next


def createLinkedList(arr):
    llist = LinkedList()
    for i in range(len(arr)):
        new_node = Node(arr[i])
        llist.append(new_node)
    return llist.head


def intersetPoint(head1, head2):
    f, s = head1, head2
    while f != s:
        f = f.next
        if f is None:
            f = head2
        s = s.next
        if s is None:
            s = head1
    if f is not None:
        return f.data
    return -1


if __name__ == "__main__":
    arr1 = [4, 4, 4, 4, 4]
    arr2 = [4, 4, 4]
    head1 = createLinkedList(arr1)
    head2 = createLinkedList(arr2)
    print(intersetPoint(head1, head2))

    arr1 = [4, 1, 8, 4, 5]
    arr2 = [5, 6, 1, 8, 4, 5]
    head1 = createLinkedList(arr1)
    head2 = createLinkedList(arr2)
    print(intersetPoint(head1, head2))

    arr1 = [1, 2, 3]
    arr2 = [4, 5, 6]
    head1 = createLinkedList(arr1)
    head2 = createLinkedList(arr2)
    print(intersetPoint(head1, head2))
