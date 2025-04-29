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


def create_looped_list(arr, pos):
    if not arr:
        return None
    head = Node(arr[0])
    tail = head
    for i in range(1, len(arr)):
        tail.next = Node(arr[i])
        tail = tail.next
    loop_here(head, pos)
    return head


class Solution:
    def loopsize(self, slow, fast):
        count = 1
        fast = fast.next

        while fast != slow:
            fast = fast.next
            count += 1
        return count

    def countNodesInLoop(self, head):
        fast = head
        slow = head

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return self.loopsize(slow, fast)
        return 0


if __name__ == "__main__":
    obj = Solution()
    arr = [25, 14, 19, 33, 10, 21, 39, 90, 59, 45]
    pos = 4
    head = create_looped_list(arr, pos)
    print("Loop Length:", obj.countNodesInLoop(head))

    arr = [0, 1, 2, 3]
    pos = 0
    head = create_looped_list(arr, pos)
    print("Loop Length:", obj.countNodesInLoop(head))
