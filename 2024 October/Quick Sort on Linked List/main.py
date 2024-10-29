# Link: https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

from collections import defaultdict


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


def nodeID(head, dic):
    while head:
        dic[head.data].append(id(head))
        head = head.next


def printList(head, dic):
    while head:
        if id(head) not in dic[head.data]:
            print("Do'nt swap data, swap pointer/node")
            return
        print(head.data, end=" ")
        head = head.next


def createLinkedList(arr):
    ll = Llist()
    tail = None
    for i in arr:
        tail = ll.insert(i, tail)
    return ll.head


def quickSort(head):
    if not head:
        return None
    pivot = head
    head = pivot.next
    lh = lt = rh = rt = None
    while head:
        if head.data < pivot.data:
            if not lh:
                lh = lt = head
            else:
                lt.next = head
                lt = lt.next
        else:
            if not rh:
                rh = rt = head
            else:
                rt.next = head
                rt = rt.next
        head = head.next
    if rh:
        rt.next = None
    pivot.next = quickSort(rh)
    if lh:
        lt.next = None
        lt = lh = quickSort(lh)
        while lt.next:
            lt = lt.next
        lt.next = pivot
        return lh
    return pivot


if __name__ == "__main__":
    arr = [3, 5, 2, 4, 1]
    head = createLinkedList(arr)
    dic = defaultdict(list)
    nodeID(head, dic)
    head = quickSort(head)
    printList(head, dic)
    print()
