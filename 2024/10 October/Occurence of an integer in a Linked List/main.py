# Link: https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1


class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


def createLinkedList(arr):
    head = Node(arr[0])
    tail = head
    for i in range(1, len(arr)):
        tail.next = Node(arr[i])
        tail = tail.next
    return head


class Solution:
    def count(self, head, key):
        res = 0
        while head is not None:
            if head.data == key:
                res += 1
            head = head.next
        return res


if __name__ == "__main__":
    ob = Solution()
    arr = [1, 2, 1, 2, 1, 3, 1]
    head = createLinkedList(arr)
    key = 1
    print(ob.count(head, key))

    arr = [1, 2, 1, 2, 1]
    head = createLinkedList(arr)
    key = 3
    print(ob.count(head, key))
