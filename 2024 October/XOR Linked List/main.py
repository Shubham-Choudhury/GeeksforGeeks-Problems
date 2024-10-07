# Link: https://www.geeksforgeeks.org/problems/xor-linked-list/1


class Node:
    def __init__(self, x):
        self.data = x
        self.npx = None


def XOR(a, b):
    return id(a) ^ id(b)


def insert(head, data):
    if head == None:
        return Node(data)
    t = Node(data)
    t.npx = head
    return t


def getList(head):
    l = []
    while head:
        l.append(head.data)
        head = head.npx
    return l


if __name__ == "__main__":
    arr = [9, 5, 4, 7, 3, 10]
    head = None
    for i in arr:
        head = insert(head, i)
    res = getList(head)
    print(" ".join(map(str, res)))

    arr = [58, 96, 31]
    head = None
    for i in arr:
        head = insert(head, i)
    res = getList(head)
    print(" ".join(map(str, res)))
