# Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

import heapq


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


def createKSortedLinkedLists(arrays):
    lists = []
    for arr in arrays:
        lists.append(createLinkedList(arr))
    return lists


def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()


class Solution:
    def mergeKLists(self, arr):
        pq = []

        for i in range(0, len(arr)):
            head = arr[i]
            if head is not None:
                heapq.heappush(pq, (head.data, i, head))

        dummy = Node(-1)
        tail = dummy

        while pq:
            _, index, top = heapq.heappop(pq)

            tail.next = top
            tail = top

            if top.next is not None:
                heapq.heappush(pq, (top.next.data, index, top.next))

        return dummy.next


if __name__ == "__main__":
    sol = Solution()
    arrays = [[1, 3, 7], [2, 4, 8], [9]]
    lists = createKSortedLinkedLists(arrays)
    print("Linked Lists are : ")
    for head in lists:
        printLinkedList(head)
    mergedHead = sol.mergeKLists(lists)
    print("Merged Linked List is : ")
    printLinkedList(mergedHead)
    print()

    arrays = [[1, 3], [8], [4, 5, 6]]
    lists = createKSortedLinkedLists(arrays)
    print("Linked Lists are : ")
    for head in lists:
        printLinkedList(head)
    mergedHead = sol.mergeKLists(lists)
    print("Merged Linked List is : ")
    printLinkedList(mergedHead)
    print()
