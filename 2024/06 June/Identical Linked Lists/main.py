# Link: https://www.geeksforgeeks.org/problems/identical-linked-lists/1


class node:

    def __init__(self, val):
        self.data = val
        self.next = None


# Linked List Class
class Linked_List:

    def __init__(self):
        self.head = None

    def insert(self, val):
        new_node = node(val)
        new_node.data = val
        new_node.next = self.head
        self.head = new_node


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()


def createList(arr, n):
    lis = Linked_List()
    for i in range(n):
        lis.insert(arr[i])
    return lis.head


def areIdentical(head1, head2):
    while head1 and head2:
        if head1.data != head2.data:
            return False

        head1 = head1.next
        head2 = head2.next

    return head1 == head2


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6]
    n = len(arr)
    head1 = createList(arr, n)
    arr = [99, 59, 42, 20]
    n = len(arr)
    head2 = createList(arr, n)
    if areIdentical(head1, head2):
        print("Identical")
    else:
        print("Not Identical")

    arr = [1, 2, 3, 4, 5]
    n = len(arr)
    head1 = createList(arr, n)
    arr = [1, 2, 3, 4, 5]
    n = len(arr)
    head2 = createList(arr, n)
    if areIdentical(head1, head2):
        print("Identical")
    else:
        print("Not Identical")
