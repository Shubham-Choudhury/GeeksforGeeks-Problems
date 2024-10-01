# Link: https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def new_node(data):
    return Node(data)


def push(head_ref, new_data):
    new_Node = new_node(new_data)
    new_Node.next = head_ref[0]
    head_ref[0] = new_Node


def reverse(r):
    prev = None
    cur = r[0]
    while cur is not None:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    r[0] = prev


def free_list(Node):
    while Node:
        temp = Node
        Node = Node.next
        del temp


def print_list(Node):
    while Node:
        print(Node.data, end=" ")
        Node = Node.next
    print()


def createLinkedList(arr):
    head = None
    for i in range(len(arr) - 1, -1, -1):
        push([head], arr[i])
    return head


class Solution:
    def multiply_two_lists(self, first, second):
        x = 0
        y = 0
        while first:
            x = ((x * 10) + first.data) % (1000000007)
            first = first.next
        while second:
            y = ((y * 10) + second.data) % (1000000007)
            second = second.next
        return (x * y) % (1000000007)


if __name__ == "__main__":
    obj = Solution()
    arr1 = [3, 2]
    arr2 = [2]
    head1 = createLinkedList(arr1)
    head2 = createLinkedList(arr2)
    print(obj.multiply_two_lists(head1, head2))

    arr1 = [1, 0, 0]
    arr2 = [1, 0]
    head1 = createLinkedList(arr1)
    head2 = createLinkedList(arr2)
    print(obj.multiply_two_lists(head1, head2))
