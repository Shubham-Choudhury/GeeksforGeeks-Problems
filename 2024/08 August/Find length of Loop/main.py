# Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def print_list(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


def loop_here(head, pos):
    if pos == 0:
        return

    walk = head
    for _ in range(1, pos):
        walk = walk.next

    tail = head
    while tail.next:
        tail = tail.next

    tail.next = walk


def createLinkedList(arr):
    head = Node(arr[0])
    walk = head
    for data in arr[1:]:
        walk.next = Node(data)
        walk = walk.next
    return head


class Solution:
    def count_loop_length(self, loop_node):
        count = 1
        temp = loop_node
        while temp.next != loop_node:
            count += 1
            temp = temp.next
        return count

    def countNodesInLoop(self, head):
        if not head or not head.next:
            return 0

        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return self.count_loop_length(slow)
        return 0


if __name__ == "__main__":
    obj = Solution()
    arr = [25, 14, 19, 33, 10, 21, 39, 90, 58, 45]
    pos = 4
    head = createLinkedList(arr)
    loop_here(head, pos)
    print(obj.countNodesInLoop(head))

    arr = [5, 4]
    pos = 0
    head = createLinkedList(arr)
    loop_here(head, pos)
    print(obj.countNodesInLoop(head))
