# Link: https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1


class Node:
    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    # Function to initialize head
    def __init__(self):
        self.head = None

    # Function to insert a new node at the beginning
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    # Utility function to prit the linked LinkedList
    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print("")


def createLinkedList(arr):
    llist = LinkedList()
    for i in range(len(arr) - 1, -1, -1):
        llist.push(arr[i])
    return llist.head


class Solution:
    def islengtheven(self, head):
        n = 0
        temp = head
        while temp is not None:
            temp = temp.next
            n += 1
        return n % 2 == 0


if __name__ == "__main__":
    object = Solution()
    arr = [12, 52, 10, 47, 95, 0]
    head = createLinkedList(arr)
    print(object.islengtheven(head))

    arr = [9, 4, 3]
    head = createLinkedList(arr)
    print(object.islengtheven(head))
