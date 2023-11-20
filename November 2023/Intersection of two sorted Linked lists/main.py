# Link: https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def findIntersection(self, head1, head2):
        # return head
        head = Node(-1)
        curr = head
        while head1 and head2:
            if head1.data == head2.data:
                curr.next = Node(head1.data)
                curr = curr.next
                head1 = head1.next
                head2 = head2.next
            elif head1.data < head2.data:
                head1 = head1.next
            else:
                head2 = head2.next
        return head.next


if __name__ == "__main__":
    obj = Solution()
    head1 = Node(1)
    head1.next = Node(2)
    head1.next.next = Node(3)
    head1.next.next.next = Node(4)
    head1.next.next.next.next = Node(5)
    head1.next.next.next.next.next = Node(6)
    head2 = Node(2)
    head2.next = Node(4)
    head2.next.next = Node(6)
    head2.next.next.next = Node(8)
    head2.next.next.next.next = Node(10)
    head2.next.next.next.next.next = Node(12)
    head = obj.findIntersection(head1, head2)
    while head:
        print(head.data, end=" ")
        head = head.next
