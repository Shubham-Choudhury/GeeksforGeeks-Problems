# Link: https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def insertionSort(self, head):
        dummy = Node(0)
        dummy.next = head
        prev, curr = head, head.next

        while curr:
            if curr.data >= prev.data:
                prev, curr = curr, curr.next
                continue

            temp = dummy
            while curr.data > temp.next.data:
                temp = temp.next

            prev.next = curr.next
            curr.next = temp.next
            temp.next = curr
            curr = prev.next

        return dummy.next


if __name__ == "__main__":
    obj = Solution()
    head = Node(30)
    head.next = Node(23)
    head.next.next = Node(28)
    head.next.next.next = Node(30)
    head.next.next.next.next = Node(11)
    head.next.next.next.next.next = Node(14)
    head.next.next.next.next.next.next = Node(19)
    head.next.next.next.next.next.next.next = Node(16)
    head.next.next.next.next.next.next.next.next = Node(21)
    head.next.next.next.next.next.next.next.next.next = Node(25)
    head = obj.insertionSort(head)
    while head:
        print(head.data, end=" ")
        head = head.next
    print()

    head2 = Node(19)
    head2.next = Node(20)
    head2.next.next = Node(16)
    head2.next.next.next = Node(24)
    head2.next.next.next.next = Node(12)
    head2.next.next.next.next.next = Node(29)
    head2.next.next.next.next.next.next = Node(30)
    head2 = obj.insertionSort(head2)
    while head2:
        print(head2.data, end=" ")
        head2 = head2.next
    print()
