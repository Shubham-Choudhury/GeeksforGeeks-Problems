# Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1


class Node:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None


def createLinkedList(arr):
    if not arr:
        return None
    head = Node(arr[0])
    curr = head
    for value in arr[1:]:
        newNode = Node(value)
        curr.next = newNode
        newNode.prev = curr
        curr = newNode
    return head


def printLinkedList(head):
    curr = head
    while curr:
        print(curr.data, end=" ")
        curr = curr.next
    print()


class Solution:
    def reverse(self, head):
        if head is None or head.next is None:
            return head

        prevNode = None
        currNode = head

        while currNode is not None:
            prevNode = currNode.prev
            currNode.prev = currNode.next
            currNode.next = prevNode

            currNode = currNode.prev

        return prevNode.prev


if __name__ == "__main__":
    sol = Solution()
    arr = [3, 4, 5]
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    reversed_head = sol.reverse(head)
    print("Reversed Linked List:")
    printLinkedList(reversed_head)

    arr = [75, 122, 59, 196]
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    reversed_head = sol.reverse(head)
    print("Reversed Linked List:")
    printLinkedList(reversed_head)
