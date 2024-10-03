# Link: https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def printList(head):
    if head is None:
        print("empty")
        return

    temp = head
    while True:
        print(temp.data, end=" ")
        temp = temp.next
        if temp == head:
            break
    print()


def createCircularLinkedList(arr):
    if len(arr) == 0:
        return None
    head = Node(arr[0])
    tail = head
    for i in range(1, len(arr)):
        new_node = Node(arr[i])
        tail.next = new_node
        new_node.next = head
        tail = new_node
    return head


class Solution:
    def reverse(self, head):
        if head is None or head.next == head:
            return head
        curr = head
        prev = None
        while True:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            if curr == head:
                break
        curr.next = prev
        return prev

    def deleteNode(self, head, key):
        if head is None or (head.next == head and head.data == key):
            return None
        if head.data == key:
            head.data = head.next.data
            head.next = head.next.next
            return head
        node = head.next
        prev = head
        while node != head:
            if node.data == key:
                prev.next = node.next
                return head
            prev = node
            node = node.next
        return head


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 5, 7, 8, 10]
    head = createCircularLinkedList(arr)
    head = obj.reverse(head)
    printList(head)
    head = obj.deleteNode(head, 7)
    printList(head)

    arr = [1, 7, 8, 10]
    head = createCircularLinkedList(arr)
    head = obj.reverse(head)
    printList(head)
    head = obj.deleteNode(head, 1)
    printList(head)
