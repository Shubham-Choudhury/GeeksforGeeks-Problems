# Link: https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1

import heapq


# A node of the doubly linked list
class DLLNode:

    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None


# Function to insert a node at the end of the doubly linked list
def push(tail, new_data):
    new_node = DLLNode(new_data)
    new_node.next = None
    new_node.prev = tail

    if tail is not None:
        tail.next = new_node

    return new_node


# Function to print nodes in a given doubly linked list
def printList(head):
    while head is not None:
        print(head.data, end=" ")
        head = head.next
    print()


def createDoublyLinkedList(arr):
    head = None
    tail = [None]
    for value in arr:
        push([head], tail, value)
        head = head if head is not None else tail[0]
    return head


class Solution:
    def sortAKSortedDLL(self, head, k):
        if not head:
            return head

        min_heap = []
        new_head = None
        sorted_tail = None
        current = head

        for i in range(k + 1):
            if current:
                heapq.heappush(min_heap, current.data)
                current = current.next

        while min_heap:
            min_value = heapq.heappop(min_heap)

            if new_head is None:
                new_head = DLLNode(min_value)
                sorted_tail = new_head
            else:
                sorted_tail.next = DLLNode(min_value)
                sorted_tail.next.prev = sorted_tail
                sorted_tail = sorted_tail.next

            if current:
                heapq.heappush(min_heap, current.data)
                current = current.next

        return new_head


if __name__ == "__main__":
    obj = Solution()

    arr = [3, 2, 1, 5, 6, 4]
    head = createDoublyLinkedList(arr)
    k = 2
    sorted_head = obj.sortAKSortedDLL(head, k)
    printList(sorted_head)

    arr = [5, 6, 7, 3, 4, 4]
    head = createDoublyLinkedList(arr)
    k = 3
    sorted_head = obj.sortAKSortedDLL(head, k)
    printList(sorted_head)
