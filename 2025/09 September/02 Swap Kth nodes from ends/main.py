# Link: https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1


class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


def create_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for value in arr[1:]:
        current.next = Node(value)
        current = current.next
    return head


def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None")


class Solution:
    def swapKth(self, head, k):
        if not head:
            return head

        n = 0
        temp = head
        while temp:
            n += 1
            temp = temp.next

        if k > n:
            return head

        if 2 * k - 1 == n:
            return head

        prevX = None
        x = head
        for i in range(1, k):
            prevX = x
            x = x.next

        prevY = None
        y = head
        for i in range(1, n - k + 1):
            prevY = y
            y = y.next

        if prevX:
            prevX.next = y
        if prevY:
            prevY.next = x

        tempNext = x.next
        x.next = y.next
        y.next = tempNext

        if k == 1:
            head = y
        if k == n:
            head = x

        return head


if __name__ == "__main__":
    sol = Solution()
    arr = [5, 2, 3, 4, 1]
    k = 1
    head = create_linked_list(arr)
    print("Original list:")
    print_linked_list(head)
    head = sol.swapKth(head, k)
    print(f"List after swapping {k}th nodes from end and start:")
    print_linked_list(head)

    arr = [5, 9, 8, 5, 10, 3]
    k = 2
    head = create_linked_list(arr)
    print("Original list:")
    print_linked_list(head)
    head = sol.swapKth(head, k)
    print(f"List after swapping {k}th nodes from end and start:")
    print_linked_list(head)
