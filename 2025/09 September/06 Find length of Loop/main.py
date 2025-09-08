# Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1


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


def createLoop(head, k):
    if k == 0:
        return
    temp = head
    count = 1
    loop_start_node = None
    while temp.next is not None:
        if count == k:
            loop_start_node = temp
        temp = temp.next
        count += 1
    temp.next = loop_start_node


def printLinkedList(head):
    temp = head
    visited = set()
    while temp is not None and temp not in visited:
        print(temp.data, end=" -> ")
        visited.add(temp)
        temp = temp.next
    if temp is not None:
        print("... (loop starts again at node with data:", temp.data, ")")
    else:
        print("None")


class Solution:
    def countNodes(self, node):
        res = 1
        curr = node
        while curr.next != node:
            res += 1
            curr = curr.next
        return res

    def lengthOfLoop(self, head):
        slow = head
        fast = head

        while slow is not None and fast is not None and fast.next is not None:

            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return self.countNodes(slow)

        return 0


if __name__ == "__main__":
    sol = Solution()

    arr = [1, 2, 3, 4, 5]
    pos = 2
    head = createLinkedList(arr)
    createLoop(head, pos)
    print("Linked List:")
    printLinkedList(head)
    length = sol.lengthOfLoop(head)
    print("Length of Loop:", length)
    print()

    arr = [25, 14, 19, 33, 10]
    pos = 3
    head = createLinkedList(arr)
    createLoop(head, pos)
    print("Linked List:")
    printLinkedList(head)
    length = sol.lengthOfLoop(head)
    print("Length of Loop:", length)
    print()

    arr = [1, 2, 3, 4, 5]
    pos = 0
    head = createLinkedList(arr)
    createLoop(head, pos)
    print("Linked List:")
    printLinkedList(head)
    length = sol.lengthOfLoop(head)
    print("Length of Loop:", length)
    print()
