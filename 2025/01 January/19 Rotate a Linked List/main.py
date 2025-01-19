# Link: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1


class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


# Function to print the linked list
def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next


def create_linked_list(arr):
    n = len(arr)
    llist = LinkedList()
    for i in range(n):
        llist.insert(arr[i])
    return llist.head


class Solution:
    def rotate(self, head, k):
        if head is None or head.next is None:
            return head

        lptr = head
        cnt = 1
        itr = lptr

        while itr.next is not None:
            itr = itr.next
            cnt += 1

        itr.next = lptr
        k = k % cnt

        for _ in range(k):
            itr = itr.next

        lptr = itr.next
        itr.next = None

        return lptr


if __name__ == "__main__":
    obj = Solution()
    arr1 = [10, 20, 30, 40, 50]
    head = create_linked_list(arr1)
    k = 4
    head = obj.rotate(head, k)
    printList(head)

    arr2 = [10, 20, 30, 40]
    head = create_linked_list(arr2)
    k = 6
    head = obj.rotate(head, k)
    printList(head)
