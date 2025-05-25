# Link: https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def createSortedCircularLinkedList(arr):
    arr.sort()
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for value in arr[1:]:
        new_node = Node(value)
        current.next = new_node
        current = new_node
    current.next = head
    return head


def printCircularLinkedList(head):
    if head is None:
        return
    current = head
    while True:
        print(current.data, end=" ")
        current = current.next
        if current == head:
            break
    print()


class Solution:

    def sortedInsert(self, head, data):
        new_node = Node(data)
        if head is None:
            new_node.next = new_node
            return new_node

        curr = head
        next_to_curr = head.next

        if data <= head.data:
            last_node = head
            while last_node.next != head:
                last_node = last_node.next
            new_node.next = head
            last_node.next = new_node
            return new_node

        while curr.next != head:
            if curr.data < data and next_to_curr.data >= data:
                new_node.next = curr.next
                curr.next = new_node
                return head
            else:
                curr = curr.next
                next_to_curr = next_to_curr.next

        new_node.next = head
        curr.next = new_node
        return head


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 4, 2]
    head = createSortedCircularLinkedList(arr)
    print("Original Circular Linked List:", end=" ")
    printCircularLinkedList(head)
    data = 2
    head = obj.sortedInsert(head, data)
    print(f"After inserting {data}:", end=" ")
    printCircularLinkedList(head)

    arr = [1, 7, 9, 4]
    head = createSortedCircularLinkedList(arr)
    print("Original Circular Linked List:", end=" ")
    printCircularLinkedList(head)
    data = 5
    head = obj.sortedInsert(head, data)
    print(f"After inserting {data}:", end=" ")
    printCircularLinkedList(head)
