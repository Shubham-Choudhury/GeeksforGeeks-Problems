# Link: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1


class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


def buildLinkedList(arr):
    head = Node(arr[0])
    temp = head
    for i in range(1, len(arr)):
        temp.next = Node(arr[i])
        temp = temp.next
    return head


class Solution:
    def rotate(self, head, k):
        if head is None or k == 0:
            return head

        count = 1
        temp = head
        for i in range(1, k):
            temp = temp.next

        thead = temp.next
        ans = thead
        temp.next = None

        while thead is not None and thead.next is not None:
            thead = thead.next

        if thead is None:
            return head
        else:
            thead.next = head
            return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 4, 7, 8, 9]
    head = buildLinkedList(arr)
    printList(head)
    k = 3
    new_head = obj.rotate(head, k)
    printList(new_head)

    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    head = buildLinkedList(arr)
    printList(head)
    k = 4
    new_head = obj.rotate(head, k)
    printList(new_head)
