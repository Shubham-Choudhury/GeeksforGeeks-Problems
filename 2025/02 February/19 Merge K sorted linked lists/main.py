# Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

import heapq


class Node:

    def __init__(self, x):
        self.data = x
        self.next = None

    # To compare nodes in the heap
    def __lt__(self, other):
        return self.data < other.data


def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


def create_linked_list(arr):
    root = Node(arr[0])
    temp = root
    for i in range(1, len(arr)):
        new_node = Node(arr[i])
        temp.next = new_node
        temp = new_node
    return root


class Solution:
    def mergeKLists(self, arr):
        pq = []
        for node in arr:
            if node is not None:
                heapq.heappush(pq, (node.data, node))

        head = None
        temp = None

        while pq:
            val, init = heapq.heappop(pq)
            if init.next is not None:
                heapq.heappush(pq, (init.next.data, init.next))
            if head is None:
                head = Node(val)
                temp = head
            else:
                new_node = Node(val)
                temp.next = new_node
                temp = new_node

        return head


if __name__ == "__main__":
    solution = Solution()
    lists = [[1, 2, 3], [4, 5], [5, 6], [7, 8]]
    arr = [create_linked_list(l) for l in lists]
    head = solution.mergeKLists(arr)
    printList(head)

    lists = [[1, 3], [8], [4, 5, 6]]
    arr.clear()
    arr = [create_linked_list(l) for l in lists]
    head = solution.mergeKLists(arr)
    printList(head)
