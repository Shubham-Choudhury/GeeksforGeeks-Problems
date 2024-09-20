# Link: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1


class Node:

    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None
        self.random = None


class LinkedList:

    def __init__(self):
        self.head = None


def insert(tail, data):
    tail.next = Node(data)
    return tail.next


def setrandom(head, a, b):
    h = head
    i = 1
    while i < a and h:
        h = h.next
        i += 1
    an = h

    h = head
    i = 1
    while i < b and h:
        h = h.next
        i += 1

    if an:
        an.random = h


def validation(head, res):

    headp = head
    resp = res

    d = {}

    while head and res:
        if head == res:
            return
        if head.data != res.data:
            return

        if head.random:
            if not res.random:
                return

            if head.random.data != res.random.data:
                return

        elif res.random:
            return
        if head not in d:
            d[head] = res
        head = head.next
        res = res.next

    if not head and res:
        return
    elif head and not res:
        return

    head = headp
    res = resp
    while head:
        if head == res:
            return
        if head.random:
            if head.random not in d:
                return
            if d[head.random] != res.random:
                return
        head = head.next
        res = res.next

    return True


def createLinkedList(arr):
    if len(arr) == 0:
        return None
    head = Node(arr[0])
    tail = head
    for i in range(1, len(arr)):
        tail = insert(tail, arr[i])
    return head


class Solution:
    def copyList(self, head):
        if head is None:
            return None
        temp = Node(head.data)
        ans = temp
        head = head.next
        while head is not None:
            temp.next = Node(head.data)
            temp.random = head.random
            temp = temp.next
            head = head.next
        return ans


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4]
    head = createLinkedList(arr)
    res = obj.copyList(head)
    result = validation(head, res)
    print(result)
    arr = [1, 3, 5, 9]
    head = createLinkedList(arr)
    res = obj.copyList(head)
    result = validation(head, res)
    print(result)
