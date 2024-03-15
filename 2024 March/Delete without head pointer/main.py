# Link: https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def deleteNode(self, del_node):
        temp = del_node.next.data
        del_node.next = del_node.next.next
        del_node.data = temp


if __name__ == "__main__":
    obj = Solution()
    node = Node(1)
    node.next = Node(2)
    obj.deleteNode(node)

    while node:
        print(node.data, end=" ")
        node = node.next
    print()

    node = Node(10)
    node.next = Node(20)
    node.next.next = Node(4)
    node.next.next.next = Node(30)
    obj.deleteNode(node.next)
    while node:
        print(node.data, end=" ")
        node = node.next
    print()
