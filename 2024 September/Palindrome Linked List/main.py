# Link: https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1


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


class Solution:
    def isPalindrome(self, head):
        if head is None or head.next is None:
            return True
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        prev = None
        current = slow
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        first_half = head
        second_half = prev
        while second_half:
            if first_half.data != second_half.data:
                return False
            first_half = first_half.next
            second_half = second_half.next
        return True


if __name__ == "__main__":
    obj = Solution()
    llist = LinkedList()
    llist.push(1)
    llist.push(2)
    llist.push(1)
    llist.push(1)
    llist.push(2)
    llist.push(1)
    llist.printList()
    print(obj.isPalindrome(llist.head))
    llist = LinkedList()
    llist.push(1)
    llist.push(2)
    llist.push(3)
    llist.push(4)
    llist.printList()
    print(obj.isPalindrome(llist.head))
