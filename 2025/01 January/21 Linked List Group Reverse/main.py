# Link:


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()


class Solution:
    def reverseKGroup(self, head, k):
        temp = head
        dum = head
        c = 0
        stack = []

        while temp is not None:
            while c < k and temp is not None:
                stack.append(temp.data)
                temp = temp.next
                c += 1
            while stack:
                dum.data = stack.pop()
                dum = dum.next
            c = 0
        return head


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    k = 4
    llist = LinkedList()
    for i in range(len(arr)):
        llist.push(arr[i])
    print("Given linked list")
    llist.printList()
    llist.head = object.reverseKGroup(llist.head, k)
    print("Reversed linked list")
    llist.printList()

    arr = [1, 2, 3, 4, 5]
    k = 3
    llist = LinkedList()
    for i in range(len(arr)):
        llist.push(arr[i])
    print("Given linked list")
    llist.printList()
    llist.head = object.reverseKGroup(llist.head, k)
    print("Reversed linked list")
    llist.printList()
