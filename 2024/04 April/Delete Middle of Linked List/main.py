# Link: https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Llist:
    def __init__(self):
        self.head = None

    def insert(self, data, tail):
        node = Node(data)

        if not self.head:
            self.head = node
            return node

        tail.next = node
        return node


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()


class Solution:
    def deleteMid(self, head):
        if not head.next:
            return
        s, f = head, head.next
        while f != None and f.next and f.next.next:
            f = f.next.next
            s = s.next
        s.next = s.next.next
        return head


if __name__ == "__main__":
    obj = Solution()
    values = [1, 2, 3, 4, 5]
    llist = Llist()
    tail = None
    for value in values:
        tail = llist.insert(value, tail)
    printList(obj.deleteMid(llist.head))

    values = [2, 4, 6, 7, 5, 1]
    llist = Llist()
    tail = None
    for value in values:
        tail = llist.insert(value, tail)
    printList(obj.deleteMid(llist.head))
