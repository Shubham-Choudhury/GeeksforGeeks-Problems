# Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


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
    head = None
    tail = None
    for i in arr:
        newNode = Node(i)
        if head is None:
            head = newNode
            tail = newNode
        else:
            tail.next = newNode
            tail = newNode
    return head


class Solution:
    def segregate(self, head):
        count0, count1, count2 = 0, 0, 0
        curr = head
        while curr != None:
            if curr.data == 0:
                count0 = count0 + 1
            elif curr.data == 1:
                count1 = count1 + 1
            else:
                count2 = count2 + 1
            curr = curr.next

        curr = head
        while curr != None:
            if count0 != 0:
                curr.data = 0
                count0 = count0 - 1
            elif count1 != 0:
                curr.data = 1
                count1 = count1 - 1
            else:
                curr.data = 2
                count2 = count2 - 1
            curr = curr.next
        return head


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 2, 1, 2, 0, 2, 2]
    head = createLinkedList(arr)
    print("Original linked list:", end=" ")
    printList(head)
    head = sol.segregate(head)
    print("Sorted linked list:", end=" ")
    printList(head)

    arr = [2, 2, 0, 1]
    head = createLinkedList(arr)
    print("Original linked list:", end=" ")
    printList(head)
    head = sol.segregate(head)
    print("Sorted linked list:", end=" ")
    printList(head)
