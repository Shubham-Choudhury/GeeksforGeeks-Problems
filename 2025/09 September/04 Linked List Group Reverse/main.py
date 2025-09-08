# Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def createLinkedList(arr):
    head = Node(arr[0])
    temp = head
    for i in range(1, len(arr)):
        temp.next = Node(arr[i])
        temp = temp.next
    return head


def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()


class Solution:
    def reverseKGroup(self, head, k):
        if head is None or k == 1:
            return head

        curr = head
        newHead = None
        tail = None

        while curr is not None:
            groupHead = curr
            prev = None
            nextNode = None
            count = 0

            while curr is not None and count < k:
                nextNode = curr.next
                curr.next = prev
                prev = curr
                curr = nextNode
                count += 1

            if newHead is None:
                newHead = prev

            if tail is not None:
                tail.next = prev

            tail = groupHead

        return newHead


if __name__ == "__main__":
    solution = Solution()

    arr = [1, 2, 3, 4, 5, 6]
    k = 2
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    newHead = solution.reverseKGroup(head, k)
    print(f"Linked List after reversing in groups of {k}:")
    printLinkedList(newHead)
    print()

    arr = [1, 2, 3, 4, 5, 6]
    k = 2
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    newHead = solution.reverseKGroup(head, k)
    print(f"Linked List after reversing in groups of {k}:")
    printLinkedList(newHead)
    print()
