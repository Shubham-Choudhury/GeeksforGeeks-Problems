# Link: https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def print_list(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


def loop_here(head, tail, position):
    if position == 0:
        return

    walk = head
    for _ in range(1, position):
        walk = walk.next
    tail.next = walk


def createLinkedList(arr):
    head = Node(arr[0])
    tail = head
    for i in arr[1:]:
        tail.next = Node(i)
        tail = tail.next
    return head, tail


class Solution:
    def findFirstNode(self, head):
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                slow = head
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return slow
        return None


if __name__ == "__main__":
    solution = Solution()
    head, tail = createLinkedList([1, 2, 3, 4, 5])
    loop_here(head, tail, 3)
    print(solution.findFirstNode(head).data)
