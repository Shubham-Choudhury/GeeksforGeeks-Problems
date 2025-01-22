# Link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1


class Node:
    def __init__(self, data):
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


def printList(n):
    while n:
        print(n.data, end=" ")
        n = n.next
    print()


def createLinkedList(arr):
    llist = LinkedList()
    for i in arr:
        llist.insert(i)
    return llist.head


class Solution:
    def reverseList(self, head):
        prev = None
        current = head
        while current is not None:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        return prev

    def addTwoLists(self, num1, num2):
        num1 = self.reverseList(num1)
        num2 = self.reverseList(num2)

        dummy = Node(0)
        current = dummy
        carry = 0

        while num1 is not None or num2 is not None or carry != 0:
            total = carry

            if num1 is not None:
                total += num1.data
                num1 = num1.next

            if num2 is not None:
                total += num2.data
                num2 = num2.next

            carry = total // 10
            current.next = Node(total % 10)
            current = current.next

        result = self.reverseList(dummy.next)

        while result is not None and result.data == 0 and result.next is not None:
            result = result.next

        return result


if __name__ == "__main__":
    obj = Solution()
    arr1 = [4, 5]
    arr2 = [3, 4, 5]
    num1 = createLinkedList(arr1)
    num2 = createLinkedList(arr2)
    result = obj.addTwoLists(num1, num2)
    printList(result)

    arr1 = [0, 0, 6, 3]
    arr2 = [0, 0, 7]
    num1 = createLinkedList(arr1)
    num2 = createLinkedList(arr2)
    result = obj.addTwoLists(num1, num2)
    printList(result)
