# Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1


class Node:
    def _init_(self, data):
        self.data = data
        self.next = None
        self.prev = None


class Solution:
    def reverseDLL(self, head):
        if not head or not head.next:
            return head

        previous_node = head.prev
        current_node = head
        next_node = head.next

        while next_node:
            current_node.prev = next_node
            current_node.next = previous_node

            previous_node = current_node
            current_node = next_node
            next_node = next_node.next

        current_node.prev = next_node
        current_node.next = previous_node

        return current_node


if __name__ == "__main__":
    obj = Solution()
    head = Node(10)
    head.next = Node(20)
    head.next.prev = head
    head.next.next = Node(30)
    print(obj.reverseDLL(head))
