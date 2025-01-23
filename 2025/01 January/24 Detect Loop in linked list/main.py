# Link: https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1


class Node:

    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next

    # connects last node to node at position pos from begining.
    def loopHere(self, pos):
        if pos == 0:
            return

        walk = self.head
        for i in range(1, pos):
            walk = walk.next

        self.tail.next = walk


def createLinkedList(arr):
    lnk_lst = LinkedList()
    for i in arr:
        lnk_lst.insert(i)
    return lnk_lst


class Solution:
    def detectLoop(self, head):
        slow = head
        fast = head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False


if __name__ == "__main__":
    solution = Solution()
    arr = [1, 3, 4]
    pos = 2
    ll = createLinkedList(arr)
    ll.loopHere(pos)
    print(solution.detectLoop(ll.head))

    arr = [1, 8, 3, 4]
    pos = 0
    ll = createLinkedList(arr)
    ll.loopHere(pos)
    print(solution.detectLoop(ll.head))

    arr = [1, 2, 3, 4]
    pos = 1
    ll = createLinkedList(arr)
    ll.loopHere(pos)
    print(solution.detectLoop(ll.head))
