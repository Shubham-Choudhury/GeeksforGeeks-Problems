# Link: https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def print_list(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()
    print("~")


def insert_sorted(head, data):
    new_node = Node(data)
    if not head or head.data >= data:
        new_node.next = head
        return new_node

    current = head
    while current.next and current.next.data < data:
        current = current.next

    new_node.next = current.next
    current.next = new_node

    return head


class LinkedList:

    def __init__(self):
        self.head = None

    def insert(self, data):
        self.head = insert_sorted(self.head, data)


def createLinkedList(arr):
    linked_list = LinkedList()
    for i in arr:
        linked_list.insert(i)
    return linked_list.head


class Solution:
    def sortedMerge(self, head1, head2):
        temp = Node(0)
        head = temp
        while head1 and head2:
            if head1.data <= head2.data:
                head.next = head1
                head1 = head1.next
            else:
                head.next = head2
                head2 = head2.next
            head = head.next
        if head1:
            head.next = head1
        else:
            head.next = head2
        return temp.next


if __name__ == "__main__":
    object = Solution()
    arr11 = [5, 10, 15, 40]
    arr12 = [2, 3, 20]
    head1 = createLinkedList(arr11)
    head2 = createLinkedList(arr12)
    merge = object.sortedMerge(head1, head2)
    print_list(merge)

    arr21 = [1, 1]
    arr22 = [2, 4]
    head1 = createLinkedList(arr21)
    head2 = createLinkedList(arr22)
    merge = object.sortedMerge(head1, head2)
    print_list(merge)
