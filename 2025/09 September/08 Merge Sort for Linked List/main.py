# Link: https://www.geeksforgeeks.org/problems/sort-a-linked-list/1


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
    def split(self, head):
        fast = head
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            if fast:
                slow = slow.next

        second = slow.next
        slow.next = None
        return second

    def merge(self, first, second):
        if not first:
            return second
        if not second:
            return first

        if first.data < second.data:
            first.next = self.merge(first.next, second)
            return first
        else:
            second.next = self.merge(first, second.next)
            return second

    def mergeSort(self, head):
        if not head or not head.next:
            return head

        second = self.split(head)

        head = self.mergeSort(head)
        second = self.mergeSort(second)

        return self.merge(head, second)


if __name__ == "__main__":
    solution = Solution()

    arr = [40, 20, 60, 10, 50, 30]
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    sorted_head = solution.mergeSort(head)
    print("Sorted Linked List:")
    printLinkedList(sorted_head)
    print()

    arr = [9, 5, 2, 8]
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    sorted_head = solution.mergeSort(head)
    print("Sorted Linked List:")
    printLinkedList(sorted_head)
    print()
