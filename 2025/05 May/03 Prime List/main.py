# Link: https://www.geeksforgeeks.org/problems/prime-list--170646/1

import bisect


class Node:

    def __init__(self, x):
        self.val = x
        self.next = None


def printList(node):
    while node != None:
        print(node.val, end=" ")
        node = node.next
    print()


def create_list(arr):
    head = Node(arr[0])
    current = head
    for i in range(1, len(arr)):
        current.next = Node(arr[i])
        current = current.next
    return head


class Solution:
    MAX_VALUE = 10100

    def _startup(max_value):
        svsize = (max_value + 1) // 2
        sv = bytearray([1]) * svsize
        sv[0] = 0
        i, p = 1, 3
        while p * p <= max_value:
            for j in range(i * (p + 1), svsize, p):
                sv[j] = 0
            i, p = i + 1, p + 2
            while sv[i] == 0:
                i, p = i + 1, p + 2

        return tuple(2 * i + 1 for i, x in enumerate(sv) if x == 1)

    ODD_PRIMES = _startup(MAX_VALUE)

    def primeList(self, head):
        node = head
        while node:
            if node.val < 5:
                node.val = 2 + (node.val > 2)
            else:
                i = bisect.bisect(self.ODD_PRIMES, node.val)
                p1, p2 = self.ODD_PRIMES[i - 1 : i + 1]
                node.val = p1 if node.val - p1 <= p2 - node.val else p2
            node = node.next

        return head


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 6, 10]
    head = create_list(arr)
    print("Original List: ", end="")
    printList(head)
    head = obj.primeList(head)
    print("Modified List: ", end="")
    printList(head)

    arr = [1, 15, 20]
    head = create_list(arr)
    print("Original List: ", end="")
    printList(head)
    head = obj.primeList(head)
    print("Modified List: ", end="")
    printList(head)
