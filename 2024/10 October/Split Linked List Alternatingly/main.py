# Link: https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1


class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


def printList(node):
    while node is not None:
        print(node.data, end=" ")
        node = node.next
    print()


def createLinkedList(arr):
    head = Node(arr[0])
    temp = head
    for i in range(1, len(arr)):
        temp.next = Node(arr[i])
        temp = temp.next
    return head


class Solution:
    def alternatingSplitList(self, head):
        if head is None:
            return [None, None]
        odd_dummy = Node(0)
        even_dummy = Node(0)
        odd = odd_dummy
        even = even_dummy
        curr = head
        o = True
        while curr is not None:
            if o:
                odd.next = curr
                odd = odd.next
            else:
                even.next = curr
                even = even.next
            curr = curr.next
            o = not o
        odd.next = None
        even.next = None
        return [odd_dummy.next, even_dummy.next]


if __name__ == "__main__":
    arr = [0, 1, 0, 1, 0, 1]
    head = createLinkedList(arr)
    ob = Solution()
    ans = ob.alternatingSplitList(head)
    printList(ans[0])
    printList(ans[1])

    arr = [2, 5, 8, 9, 6]
    head = createLinkedList(arr)
    ans = ob.alternatingSplitList(head)
    printList(ans[0])
    printList(ans[1])
