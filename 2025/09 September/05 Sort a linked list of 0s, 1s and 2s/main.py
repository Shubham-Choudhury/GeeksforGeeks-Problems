# Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def createLinkedList(arr):
    head = Node(arr[0])
    temp = head
    for i in range(1, len(arr)):
        temp.next = Node(arr[i])
        temp = temp.next
    return head


def printLinkedList(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()


class Solution:
    def segregate(self, head):
        zeroD = Node(0)
        oneD = Node(1)
        twoD = Node(2)

        zero = zeroD
        one = oneD
        two = twoD

        curr_node = head

        while curr_node:
            if curr_node.data == 0:
                zero.next = curr_node
                zero = zero.next
            elif curr_node.data == 1:
                one.next = curr_node
                one = one.next
            else:
                two.next = curr_node
                two = two.next
            curr_node = curr_node.next

        if oneD.next:
            zero.next = oneD.next
        else:
            zero.next = twoD.next
        one.next = twoD.next
        two.next = None

        return zeroD.next


if __name__ == "__main__":
    solution = Solution()

    arr = [1, 2, 2, 1, 2, 0, 2, 2]
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    sorted_head = solution.segregate(head)
    print("Sorted Linked List:")
    printLinkedList(sorted_head)
    print()

    arr = [2, 2, 0, 1]
    head = createLinkedList(arr)
    print("Original Linked List:")
    printLinkedList(head)
    sorted_head = solution.segregate(head)
    print("Sorted Linked List:")
    printLinkedList(sorted_head)
    print()
