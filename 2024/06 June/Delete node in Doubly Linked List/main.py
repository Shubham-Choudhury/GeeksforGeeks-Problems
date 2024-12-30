# Link: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

    @staticmethod
    def print_list(node):
        while node is not None:
            print(node.data, end=" ")
            node = node.next
        print()


def createLinkedList(arr):
    head = Node(arr[0])
    last = head
    for value in arr[1:]:
        last.next = Node(value)
        last.next.prev = last
        last = last.next
    return head


class Solution:
    def delete_node(self, head, x):
        if x == 1:
            head = head.next
            head.prev = None
            return head

        cnt = 1
        temp = head
        while cnt < (x - 1):
            temp = temp.next
            cnt += 1
        temp.next = temp.next.next
        return head


if __name__ == "__main__":
    obj = Solution()
    head = createLinkedList([1, 3, 4])
    obj.delete_node(head, 3)
    Node.print_list(head)

    head = createLinkedList([1, 5, 2, 9])
    obj.delete_node(head, 1)
    Node.print_list(head)
