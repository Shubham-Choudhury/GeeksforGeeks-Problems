# Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1


class Node:

    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, value):
        if self.head is None:
            self.head = Node(value)
            self.tail = self.head
        else:
            self.tail.next = Node(value)
            self.tail = self.tail.next


def PrintList(head):
    while head:
        print(head.data, end="")
        head = head.next


class Solution:
    def addOne(self, head):
        def reverse(h):
            cur = h
            prev = None
            while cur:
                r = cur.next
                cur.next = prev
                prev = cur
                cur = r
            return prev

        t = reverse(head)
        h1 = t
        carry = 0
        ele = h1.data + 1
        if ele == 10:
            h1.data = 0
            carry = 1
        else:
            h1.data += 1
            carry = 0
        h1 = h1.next
        while h1 and carry:
            h1.data += carry
            if h1.data == 10:
                h1.data = 0
                carry = 1
            else:
                carry = 0
            if h1.next is None and carry:
                nn = Node(1)
                h1.next = nn
                carry = 0
            h1 = h1.next
        h2 = reverse(t)
        return h2


if __name__ == "__main__":
    obj = Solution()
    arr = [4, 5, 6]
    n = len(arr)
    llist = LinkedList()
    for i in range(n):
        llist.insert(arr[i])
    res = obj.addOne(llist.head)
    PrintList(res)
    print()
    arr = [1, 2, 3]
    n = len(arr)
    llist = LinkedList()
    for i in range(n):
        llist.insert(arr[i])
    res = obj.addOne(llist.head)
    PrintList(res)
