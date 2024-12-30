# Link: https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1


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
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node

    # prints the elements of linked list starting with head
    def printList(self, head):
        if head is None:
            print(" ")
            return
        curr_node = head
        while curr_node:
            print(curr_node.data, end=" ")
            curr_node = curr_node.next
        print(" ")


class Solution:
    def remove_all_duplicates(self, head):
        temp = head
        new_head = None
        prev = None
        while temp:
            if temp.next:
                if temp.data == temp.next.data:
                    while temp.next and temp.data == temp.next.data:
                        temp = temp.next
                    if prev is None:
                        temp = temp.next
                        new_head = temp
                    else:
                        prev.next = temp.next
                        temp = temp.next
                else:
                    if prev is None:
                        prev = temp
                        new_head = temp
                    else:
                        prev = prev.next
                    temp = temp.next
            else:
                return new_head
        return new_head


if __name__ == "__main__":
    obj = Solution()
    elements = [23, 28, 28, 35, 49, 49, 53, 53]
    ll = LinkedList()
    for i in elements:
        ll.append(i)
    new_head = obj.remove_all_duplicates(ll.head)
    ll.printList(new_head)

    elements = [11, 11, 11, 11, 75, 75]
    ll = LinkedList()
    for i in elements:
        ll.append(i)
    new_head = obj.remove_all_duplicates(ll.head)
    ll.printList(new_head)
