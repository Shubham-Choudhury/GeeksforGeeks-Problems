# Link: https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1


class Node:

    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def print_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()


def createDLL(arr):
    head = Node(arr[0])
    temp = head
    for ele in arr[1:]:
        temp.next = Node(ele)
        temp.next.prev = temp
        temp = temp.next
    return head


class Solution:
    def sortedInsert(self, head, x):
        insert = Node(x)

        if x <= head.data:
            insert.next = head
            head.prev = insert
            return insert

        curr = head.next
        prev = head

        while curr is not None and x > curr.data:
            prev = curr
            curr = curr.next

        prev.next = insert
        insert.prev = prev

        if curr is not None:
            curr.prev = insert
            insert.next = curr

        return head


if __name__ == "__main__":
    obj = Solution()
    arr = [3, 5, 8, 10, 12]
    head = createDLL(arr)
    x = 9
    head = obj.sortedInsert(head, x)
    print_list(head)

    arr = [1, 4, 10, 11]
    head = createDLL(arr)
    x = 15
    head = obj.sortedInsert(head, x)
    print_list(head)
