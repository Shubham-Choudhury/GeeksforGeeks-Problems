# Link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1


# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

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


class Solution:
    def addTwoLists(self, num1, num2):
        sum1 = 0
        sum2 = 0
        dummy = Node(0)
        prev = dummy
        while num1:
            sum1 = sum1 * 10 + num1.data
            num1 = num1.next
        while num2:
            sum2 = sum2 * 10 + num2.data
            num2 = num2.next

        total = str(sum1 + sum2)
        for i in total:
            prev.next = Node(i)
            prev = prev.next
        return dummy.next


if __name__ == "__main__":
    obj = Solution()
    val1 = [4, 5]
    val2 = [3, 4, 5]
    num1 = LinkedList()
    num2 = LinkedList()
    for i in val1:
        num1.insert(i)
    for i in val2:
        num2.insert(i)
    res = obj.addTwoLists(num1.head, num2.head)
    printList(res)

    val1 = [0, 0, 6, 3]
    val2 = [0, 7]
    num1 = LinkedList()
    num2 = LinkedList()
    for i in val1:
        num1.insert(i)
    for i in val2:
        num2.insert(i)
    res = obj.addTwoLists(num1.head, num2.head)
    printList(res)
