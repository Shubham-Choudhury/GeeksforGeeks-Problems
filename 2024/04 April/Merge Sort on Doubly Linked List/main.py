# Link: https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1

import sys

sys.setrecursionlimit(1000000)


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        new_node.prev = self.tail
        self.tail.next = new_node
        self.tail = new_node

    def printList(self, node):
        while node.next is not None:
            node = node.next
        while node.prev is not None:
            node = node.prev
        while node is not None:
            print(node.data, end=" ")
            node = node.next
        print()


class Solution:
    def sortDoubly(self, head):
        if head is None:
            return head
        if head.next is None:
            return head

        second = self.split(head)

        head = self.sortDoubly(head)
        second = self.sortDoubly(second)

        return self.merge(head, second)

    def merge(self, first, second):
        if first is None:
            return second

        if second is None:
            return first

        if first.data < second.data:
            first.next = self.merge(first.next, second)
            first.next.prev = first
            first.prev = None
            return first
        else:
            second.next = self.merge(first, second.next)
            second.next.prev = second
            second.prev = None
            return second

    def split(self, head):
        fast = slow = head
        while True:
            if fast.next is None:
                break
            if fast.next.next is None:
                break
            fast = fast.next.next
            slow = slow.next

        temp = slow.next
        slow.next = None
        return temp


if __name__ == "__main__":
    obj = Solution()
    values = [7, 3, 5, 2, 6, 4, 1, 8]
    dll = DoublyLinkedList()
    for i in values:
        dll.append(i)
    sorted_head = obj.sortDoubly(dll.head)
    dll.printList(sorted_head)

    values = [9, 15, 0, -1, 0]
    dll = DoublyLinkedList()
    for i in values:
        dll.append(i)
    sorted_head = obj.sortDoubly(dll.head)
    dll.printList(sorted_head)
