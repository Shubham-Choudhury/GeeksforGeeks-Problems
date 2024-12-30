# Link: https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


class Solution:
    def subLinkedList(self, l1, l2):
        sum1 = 0
        sum2 = 0

        while l1 is not None:
            sum1 = sum1 * 10 + l1.data
            l1 = l1.next

        while l2 is not None:
            sum2 = sum2 * 10 + l2.data
            l2 = l2.next
        node = Node(abs(sum1 - sum2))

        return node


if __name__ == "__main__":
    obj = Solution()

    l1 = LinkedList()
    l1.insert(1)
    l1.insert(0)
    l1.insert(0)
    l2 = LinkedList()
    l2.insert(1)
    l2.insert(2)
    result = obj.subLinkedList(l1.head, l2.head)
    while result:
        print(result.data, end=" ")
        result = result.next
    print()
    l1 = LinkedList()
    l1.insert(0)
    l1.insert(0)
    l1.insert(6)
    l1.insert(3)
    l2 = LinkedList()
    l2.insert(7)
    l2.insert(1)
    l2.insert(0)
    result = obj.subLinkedList(l1.head, l2.head)
    while result:
        print(result.data, end=" ")
        result = result.next
    print()
