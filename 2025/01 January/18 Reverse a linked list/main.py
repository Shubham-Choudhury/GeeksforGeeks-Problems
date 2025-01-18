# Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1


class Node:

    def __init__(self, val):
        self.data = val
        self.next = None


# Linked List Class
class Linked_List:

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


def createLinkedList(arr):
    n = len(arr)
    if n == 0:
        return None
    llist = Linked_List()
    for i in range(n):
        llist.insert(arr[i])
    return llist.head


def printList(head):
    tmp = head
    while tmp:
        print(tmp.data, end=" ")
        tmp = tmp.next
    print()


class Solution:
    def reverseList(self, head):
        temp = head
        prev = None
        forward = None
        while temp:
            forward = temp.next
            temp.next = prev
            prev = temp
            temp = forward
        return prev


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 3, 4, 5]
    head = createLinkedList(arr)
    head = object.reverseList(head)
    printList(head)

    arr = [2, 7, 8, 9, 10]
    head = createLinkedList(arr)
    head = object.reverseList(head)
    printList(head)
