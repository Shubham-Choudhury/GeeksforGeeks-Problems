# Link: https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


def createLinkedList(arr):
    head = Node(arr[0])
    last = head
    for val in arr[1:]:
        last.next = Node(val)
        last = last.next
    return head


class Solution:
    def deleteAlt(self, head):
        curr = head
        while curr and curr.next:
            curr.next = curr.next.next
            curr = curr.next


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 5, 6]
    head = createLinkedList(arr)
    obj.deleteAlt(head)
    while head is not None:
        print(head.data, end=" ")
        head = head.next
    print()

    arr = [99, 59, 42, 20]
    head = createLinkedList(arr)
    obj.deleteAlt(head)
    while head is not None:
        print(head.data, end=" ")
        head = head.next
    print()
